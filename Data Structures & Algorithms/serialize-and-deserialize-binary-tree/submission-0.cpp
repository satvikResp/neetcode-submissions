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

class Codec {
public:
    string encoded;
    vector<int>decoded;
    void preorder(TreeNode *root){
        if(root==nullptr) {
           
            encoded+='#';
            encoded+=',';
            return;
        }
        
        encoded+=to_string(root->val);
        encoded+=',';
        preorder(root->left);
        preorder(root->right);
        return;
    }
    string serialize(TreeNode* root) {
        preorder(root);
        // encoded.erase(encoded.size()-1,1);
        return encoded;
    }

    
    TreeNode* attach(vector<int>& pre, int& i) {

    if (pre[i] == -1001){
        i++;
        return nullptr;
    }
    TreeNode* root = new TreeNode(pre[i]);
    i++;

    root->left = attach(pre, i);
    root->right = attach(pre, i);

    return root;
}

    TreeNode* deserialize(string data) {
        string curr;
        stringstream ss(data);
        while(getline(ss,curr,',')){
            if(curr=="#") {
            decoded.push_back(-1001);
            continue;
            }
            decoded.push_back(stoi(curr));
        }
        int i=0;
        return attach(decoded,i);

    }
};
