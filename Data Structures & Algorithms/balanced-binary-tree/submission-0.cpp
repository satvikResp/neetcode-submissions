class Solution {

public:

    pair<int,bool> check(TreeNode *root){
        if(root==nullptr) return {0,true};
        pair<int,bool>lh,rh;
         lh=check(root->left);
         rh=check(root->right);
        if(lh.second ==false|| rh.second ==false ) return {0,false};
        int maxh=max(lh.first,rh.first);
        bool chck =false;
        int diff=abs(lh.first-rh.first);
        if(diff<=1){
            chck=true;
        }
        return {maxh+1,chck};
    }

    bool isBalanced(TreeNode* root) {

        return check(root).second;

    }

}; 