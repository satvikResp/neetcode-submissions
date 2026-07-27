 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>>res;
        if(root==nullptr){
            return res;
        }
    
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>levels;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode *node = q.front();
                q.pop();
                levels.push_back(node->val);
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            res.push_back(levels);
        }
        return res;
    }
};
