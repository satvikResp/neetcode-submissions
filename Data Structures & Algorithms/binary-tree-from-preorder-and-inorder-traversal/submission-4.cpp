class Solution {
public:
    unordered_map<int, int> mp;
    

    TreeNode* dfs(vector<int>& preorder, int start, int end,int &idx) {
        // No element in this range
        if (start > end) {
            return nullptr;
        }

        // Preorder gives us the root
        int rootVal = preorder[idx];
        idx++;
        TreeNode* root = new TreeNode(rootVal);

        // Find root's position in inorder
        int i = mp[rootVal];

        // Build left and right subtrees
        root->left = dfs(preorder, start, i - 1,idx);
        root->right = dfs(preorder, i + 1, end,idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder value -> index
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int idx=0;
        // Start with the complete inorder range
        return dfs(preorder, 0, inorder.size() - 1,idx);
    }
};