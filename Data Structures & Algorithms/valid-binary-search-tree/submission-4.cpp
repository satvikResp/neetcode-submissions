class Solution {
public:
    bool traverseinorder(TreeNode* root, int& prev) {

        if (!root) {
            return true;
        }

        // Left
        auto lans = traverseinorder(root->left, prev);
        if (lans == false)
            return false;

        // Current
        if (prev != INT_MIN && root->val <= prev)
            return false;

        prev = root->val;

        // Right
        auto rans = traverseinorder(root->right, prev);
        if (rans == false)
            return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        int prev = INT_MIN;
        return traverseinorder(root, prev);
    }
};