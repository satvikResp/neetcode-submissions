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
    TreeNode * traverse(TreeNode *root,int key){
        if(root==nullptr) return nullptr;

        if(root->val>key){
            root->left=traverse(root->left,key);
        }
        else if(root->val<key){
            root->right=traverse(root->right,key);
        }
        else{
            //inorder successor
            
            if(root->right==nullptr &&root ->left==nullptr) return nullptr;
            if(root->left==nullptr) return root->right;
            if(root->right==nullptr) return root->left;
            TreeNode *node=root->right;
            while(node->left!=nullptr){
                node=node->left;
            }
            TreeNode * newnode=new TreeNode(node->val);
            root->right=traverse(root->right,node->val);

            newnode->left=root->left;
            newnode->right=root->right;
            return newnode;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return traverse(root,key);
    }
};