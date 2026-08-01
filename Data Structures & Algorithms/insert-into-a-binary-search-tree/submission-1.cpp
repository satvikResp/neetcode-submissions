class Solution {
public:

    TreeNode* location(TreeNode* root, int val) {

        if (root == nullptr)
            return nullptr;

        if (val < root->val) {

            TreeNode* ans = location(root->left, val);

            if (ans == nullptr)
                return root;

            return ans;
        }

        else {

            TreeNode* ans = location(root->right, val);

            if (ans == nullptr)
                return root;

            return ans;
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if (root == nullptr)
            return new TreeNode(val);

        TreeNode* node = location(root, val);

        if (val < node->val)
            node->left = new TreeNode(val);
        else
            node->right = new TreeNode(val);

        return root;
    }
};