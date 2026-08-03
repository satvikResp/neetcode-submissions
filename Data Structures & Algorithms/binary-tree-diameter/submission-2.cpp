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
    int ans=0;
    int calculatedfs(TreeNode *root){
        if(root==nullptr) return 0;

        int lans=calculatedfs(root->left);
        int rans=calculatedfs(root->right);
        ans=max(ans,lans+rans);
        return 1+max(lans,rans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
         calculatedfs(root);
         return ans;
    }
};
