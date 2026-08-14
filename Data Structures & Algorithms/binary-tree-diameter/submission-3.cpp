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
    int dfs(TreeNode *root,int &maxlen){
        if(!root) return -1;
        int l=dfs(root->left,maxlen)+1;
        int r=dfs(root->right,maxlen)+1;
        maxlen=max(maxlen,l+r);
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxlen=0;
        int ans= dfs(root,maxlen);
        return max(ans,maxlen);
    }
};
