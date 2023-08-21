// this is the solution to leetcode 701: Insert into a Binary Search Tree.

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
    void helper(TreeNode*& root, int val){
        // base case
        if(root==NULL){
            root = new TreeNode;
            root->val = val;
            return;
        }
        // general case
        if(val<root->val){
            helper(root->left, val);
        }else{
            helper(root->right, val);
        }
        return;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        helper(root, val);
        return root;
    }
};
