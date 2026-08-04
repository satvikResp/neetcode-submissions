/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool traverseinorder(TreeNode* root, int& prev) {
    if (!root)
        return true;

    // Left
    if (!traverseinorder(root->left, prev))
        return false;

    // Current
    if (prev != INT_MIN && root->val <= prev)
        return false;

    prev = root->val;

    // Right
    if (!traverseinorder(root->right, prev))
        return false;

    return true;
}
    bool isValidBST(TreeNode* root) {
        int prev=INT_MIN;
        return traverseinorder(root,prev);
    }
};
