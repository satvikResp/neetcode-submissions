class Solution {
public:
    unordered_map<int, int> mp;
    int pre_idx = 0;

    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        // No element in this range
        if (l > r) {
            return nullptr;
        }

        // Preorder gives us the root
        int rootVal = preorder[pre_idx++];
        TreeNode* root = new TreeNode(rootVal);

        // Find root's position in inorder
        int mid = mp[rootVal];

        // Build left and right subtrees
        root->left = dfs(preorder, l, mid - 1);
        root->right = dfs(preorder, mid + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder value -> index
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        // Start with the complete inorder range
        return dfs(preorder, 0, inorder.size() - 1);
    }
};