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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>arr;
        
        while(!q.empty()){
            vector<int>level;
            int n=q.size();
            int i=0;
            while(i<n){
                if(q.front()->left!=nullptr)
                q.push(q.front()->left);
                if(q.front()->right!=nullptr)
                q.push(q.front()->right);
                level.push_back(q.front()->val);
                q.pop();
                i++;
            }
            arr.push_back(level);
        }
        return arr;
       
    }
};
