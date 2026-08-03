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
    pair<bool,int> checkdfs(TreeNode *root){
        if(!root) return {true,0};

        auto lans=checkdfs(root->left);
        auto rans=checkdfs(root->right);

        if(!lans.first || !rans.first) return {false,0};
        if(abs(lans.second-rans.second)<=1) return {true,1+max(lans.second,rans.second)};
        return {false,0};
    }
    bool isBalanced(TreeNode* root) {
        auto ans=checkdfs(root);
        return ans.first;
    }
};
