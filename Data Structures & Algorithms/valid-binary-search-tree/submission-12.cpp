class Solution {
public:
    struct info {
        bool isbst;
        int max;
        int min;
    };

    info dfs(TreeNode* root) {
        if (!root) {
            return {true, INT_MIN, INT_MAX};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (!left.isbst || !right.isbst) {
            return {false, 0, 0};
        }

        if (left.max >= root->val || right.min <= root->val) {
            return {false, 0, 0};
        }

        return {
            true,
            max(root->val, right.max),
            min(root->val, left.min)
        };
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root).isbst;
    }
};