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
    
     int maxisum=INT_MIN;
    int dfs(TreeNode *root){
        if(!root) return 0;
        
       int lans = max(0, dfs(root->left));
       int rans = max(0, dfs(root->right));

        maxisum=max(maxisum,lans+rans+root->val);
        int maxi=max(lans,rans);

        return root->val+maxi;

 
    }
    int maxPathSum(TreeNode* root) {
         int value =dfs(root);
         return max(maxisum,value);
        
    }
};
