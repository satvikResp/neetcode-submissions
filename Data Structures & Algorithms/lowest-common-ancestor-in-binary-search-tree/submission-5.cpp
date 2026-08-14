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

    TreeNode* lca(TreeNode *root, TreeNode* p, TreeNode* q){
        if(root==nullptr) return nullptr;
        if(p->val<=root->val &&root->val<=q->val) return root;
        if(root->val>p->val && root->val>q->val) return lca(root->left,p,q);
        else return lca(root->right,p,q);
       
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val) swap(p,q);
        return lca(root,p,q);
    }
};
