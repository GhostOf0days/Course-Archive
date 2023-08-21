// in our lecture, this is the erase node function.
// leetcode 450, also known as delete node in a binary search tree.

class Solution {
public:
    // search this tree, and return the root of this tree (after deletion)
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
       if(root==NULL){
           return NULL;
       }
       //
       if(root->val == key){
           // leaf node
           if(root->left==NULL && root->right==NULL){
               return NULL;
           }else if(root->left==NULL && root->right!=NULL){
               // non-leaf, has right child only
                return root->right;
           }else if(root->left!=NULL && root->right==NULL){
                // non-leaf, has left child only
                return root->left;
            }else{
                // has two children
                TreeNode* tmp;
                tmp=root->right;
                while(tmp->left){
                    tmp = tmp->left;
                }
                root->val = tmp->val;   // we are deleting 3; tmp->val is 4;
                root->right=deleteNode(root->right, tmp->val);
                return root;
            }

       }
       // general case
       if(root->val > key){
           root->left=deleteNode(root->left, key);
           return root;
       }else{
           // root->val < key
           root->right=deleteNode(root->right, key);
           return root;
       }
    }
};
