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
    bool sametree(TreeNode *root,TreeNode *subroot){
        if(root==nullptr && subroot==nullptr) return true;
        if(root==nullptr) return false;
        if(subroot==nullptr) return false;

        if(root->val!=subroot->val) return false;
        return sametree(root->left ,subroot->left) && sametree(root->right,subroot->right);
    }
    bool dfs(TreeNode *root,TreeNode *subroot){
        if(root==nullptr && subroot==nullptr) return true;
        if(root==nullptr) return false;
        if(subroot==nullptr) return false;
        if(root->val==subroot->val)  {
            if(sametree(root,subroot)) return true;
        } 
        return dfs(root->left,subroot) || dfs(root->right,subroot);

    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        return dfs(root,subroot);
    }
};
