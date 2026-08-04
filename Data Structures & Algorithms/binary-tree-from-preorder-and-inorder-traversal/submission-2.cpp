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
    pair<TreeNode*,bool> check(TreeNode *root,int value,unordered_map<int,int>&i_map){
            if(!root) return {nullptr,0};

            if(i_map[root->val]>i_map[value]){
                //index kam hai to left side jao     left =1
                auto lans=check(root->left,value,i_map);
                if(lans.first==nullptr) return {root,1};
                else return {lans.first,lans.second};

            }
            else{
                auto rans=check(root->right,value,i_map);
                if(rans.first==nullptr) return {root,0};
                else return {rans.first,rans.second};
            }
            
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inordermap;
        for(int i=0;i<inorder.size();i++){
            inordermap[inorder[i]]=i;
        }
        TreeNode *root=new TreeNode(preorder[0]); 
        
        for(int i=1;i<preorder.size();i++){
         auto ans= check(root,preorder[i],inordermap);
         TreeNode *newnode=new TreeNode(preorder[i]);
         if(ans.second==1){
            ans.first->left=newnode;
         }
         else{
            ans.first->right=newnode;
         }
        }

        return root;
    }
};