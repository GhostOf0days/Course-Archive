// leetcode 104, also known as maximum depth of a binary tree.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // base case
        if(root==NULL){
            return 0;
        }
        // general case
        // if we know left height is l_h, we know right height is r_h;
        return (1 + max(maxDepth(root->left), maxDepth(root->right)) );
    }
};
