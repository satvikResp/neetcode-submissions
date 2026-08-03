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
    int dfs(TreeNode *root,int maxi){
        if(root==nullptr){
            return 0;
        }
       
        int lans = dfs(root->left,max(maxi,root->val));
        int rans = dfs(root->right,max(maxi,root->val));
        if(root->val>=maxi)
        return lans+rans+1;
        else return lans+rans;

    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
