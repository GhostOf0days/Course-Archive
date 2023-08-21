// leetcode problem 111, also know as Minimum Depth of a binary tree.

class Solution {
public:
    int minDepth(TreeNode* root) {
        // base case
        if(root==NULL){
            return 0;
        }
        // general case
        if(root->left!=NULL && root->right!=NULL){
            // if we know left shortest path is l_h, we know right shortest path is r_h;
            return (1 + min(minDepth(root->left), minDepth(root->right)) );
        }else if(root->left!=NULL && root->right==NULL){
            // have left only
            return (1 + minDepth(root->left));
        }else if(root->left==NULL && root->right!=NULL){
            // have right only
            return (1 + minDepth(root->right));
        }else{
            // no children
            return 1;
        }
    }
};
