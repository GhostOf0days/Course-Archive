// solution to leetcode problem 508

class Solution {
public:
    // compute the sum of this subtree
    int helper(TreeNode* root, vector<int>& ans, unordered_map<int,int>& map1, int& max){
        int sum;
        // base case
        if(root==NULL){
            return 0;
        }
        // base case 2
        if(root->left==NULL && root->right==NULL){
            // leaf node itself is a subtree
            sum = root->val;
            map1[sum]++;
            if(map1[sum]>max){
                // update max
                max = map1[sum];
            }
            return root->val;
        }
        // general case
        // sum is always
        sum = root->val + helper(root->left, ans, map1, max) + helper(root->right, ans, map1, max);
        map1[sum]++;
        if(map1[sum]>max){
            // update max
            max = map1[sum];
        }
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        // use max to track frequency of the most frequent subtree sum.
        int max = 0;
        // map subtree sum to frequency
        unordered_map<int,int> map1;
        vector<int> ans;
        helper(root, ans, map1, max);
        unordered_map<int,int>::iterator itr=map1.begin();
        while(itr!=map1.end()){
            // if frequency of this sum equals to max, then this sum is what we are looking for.
            if(itr->second==max){
                ans.push_back(itr->first);
            }
            itr++;
        }
        return ans;
    }
};
