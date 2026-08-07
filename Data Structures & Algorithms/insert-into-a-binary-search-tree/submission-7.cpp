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
    TreeNode* dfs(TreeNode *root,TreeNode *node){
        if(!root) return node;
        if(root->val>node->val){
            root->left=dfs(root->left,node);
            return root;
        }
        else{
          root->right=dfs(root->right,node);
            return root;
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       
        TreeNode *newnode=new TreeNode(val);
         if(!root) return newnode;
        return dfs(root,newnode);
    }
};