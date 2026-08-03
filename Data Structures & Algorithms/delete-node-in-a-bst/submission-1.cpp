
class Solution {
public:
    TreeNode *remove(TreeNode *root,int key){
        if(!root) return nullptr;

        if(root->val>key){
            root->left=remove(root->left,key);
            return root;
        }
        else if(root->val<key){
            root->right=remove(root->right,key);
            return root;
        }
        else{
            //going to the inorder successor mtlb right side me sabse chota node
            if(!root->left && !root->right) return nullptr;
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            TreeNode *temp=root->right;
            while(temp->left!=nullptr){
                temp=temp->left;
            }

            //now temp is the node we want to attach in place of the key node will be done using return temp
            //now we have to delete this temp node in the og tree to avoid two nodes having same val

            root->right=remove(root->right,temp->val);

            temp->left = root->left;
            temp->right = root->right;

            return temp;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return remove(root,key);
    }
};
