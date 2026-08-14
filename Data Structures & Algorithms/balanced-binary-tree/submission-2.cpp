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
    int dfs(TreeNode *root,bool &check){
        if(!root) return -1;
        int l=dfs(root->left,check)+1;
        int r=dfs(root->right,check)+1;
        if(abs(r-l)>1) check=false;
        return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        bool ck=true;
        dfs(root,ck);
        return ck;
    }
};
