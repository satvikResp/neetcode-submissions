class Solution {
public:
    int ans;

    void dfs(TreeNode* root, int& k) {
        if (!root) return;

        dfs(root->left, k);

        k--;

        if (k == 0) {
            ans = root->val;
            return;
        }

        dfs(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};