class Solution {
public:
TreeNode* deletenode(TreeNode* root, int key) {

    if (root == nullptr)
        return nullptr;

    if (key < root->val) {

        root->left = deletenode(root->left, key);
    }

    else if (key > root->val) {

        root->right = deletenode(root->right, key);
    }

    else {

        if (root->left == nullptr)
            return root->right;

        if (root->right == nullptr)
            return root->left;

        TreeNode* successor = root->right;

        while (successor->left != nullptr)
            successor = successor->left;

        root->val = successor->val;

        root->right = deletenode(root->right, successor->val);
    }

    return root;
}

    TreeNode* deleteNode(TreeNode* root, int key) {
        return deletenode(root, key);
    }
};


 