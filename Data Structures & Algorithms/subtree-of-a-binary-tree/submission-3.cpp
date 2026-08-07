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

        if(root==nullptr||subroot==nullptr) return false;

        if(root->val!=subroot->val) return false;
        return sametree(root->left,subroot->left) && sametree(root->right,subroot->right);
    }
    TreeNode *find(TreeNode *root,TreeNode *subroot){
        if(root==nullptr) return nullptr;

        if(root->val==subroot->val){
            if(sametree(root,subroot)) return root;
        }
        auto lans=find(root->left,subroot);
        if(lans!=nullptr) return lans;
        auto rans=find(root->right,subroot);
        if(rans!=nullptr) return rans;
        return nullptr;
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        auto loc = find(root,subRoot);
        if(loc==nullptr) return false;
        return true;
    }
};
