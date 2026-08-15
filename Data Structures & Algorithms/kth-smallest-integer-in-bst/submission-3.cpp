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
    int dfs(TreeNode *root,int &k){
        if(!root) return 0;

        auto lans=dfs(root->left,k);
        if(lans!=0) return lans;
        k--;
        if(k==0) return root->val;
     
        auto rans=dfs(root->right,k);
        if(rans!=0) return rans;
        
    return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root,k);
    }
};
