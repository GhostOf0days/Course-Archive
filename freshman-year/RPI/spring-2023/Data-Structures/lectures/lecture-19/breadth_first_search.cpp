// bfs search of a binary tree
// leetcode 102.

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode*> current_level;
        vector<TreeNode*> next_level;
        if(root==NULL){
            return {};
        }
        current_level.push_back(root);
        int size = current_level.size();
        while(size!=0){
            // storing values of this current level
            vector<int> tmp;
            // traversing each node of this current level
            for(int i=0;i<size;i++){
                tmp.push_back(current_level[i]->val);
                // this node has a left
                if(current_level[i]->left){
                    next_level.push_back(current_level[i]->left);
                }
                // this node has a right
                if(current_level[i]->right){
                    next_level.push_back(current_level[i]->right);
                }
            }
            current_level=next_level;
            size = current_level.size();
            ans.push_back(tmp);
            next_level.clear();
            
        }
        return ans; 
    }
};
