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
    TreeNode* traverse(TreeNode* root,int val){
        if(root==nullptr) return nullptr;

        if(root->val>val){
            auto leftans=traverse(root->left,val);
            if(leftans==nullptr) return root;
            return leftans;
        }
        else{
            auto rightans=traverse(root->right,val);
            if(rightans==nullptr) return root;
            return rightans;
        }
     return nullptr;

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
    return new TreeNode(val);
       auto ans= traverse(root,val);
       TreeNode* newnode=new TreeNode(val);
       if(ans->val>val) ans->left=newnode;
       else ans->right=newnode;
       return root;
    }
};