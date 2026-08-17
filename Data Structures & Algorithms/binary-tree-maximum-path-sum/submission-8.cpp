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
        //sum,maxsum
    int dfs(TreeNode *root,int &maxsum){
        if(!root) return 0;
        int left = dfs(root->left,maxsum);
        if(left<0) left=0;
        int right=dfs(root->right,maxsum);
        if(right<0) right=0;
        maxsum=max(left+right+root->val,maxsum);
        int correct=max(left,right);
        int sum=correct+root->val;
        // if(sum<0) sum=0;
        

        // if(sum<0) return 0;
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        dfs(root,sum);
        return sum;
    }
};