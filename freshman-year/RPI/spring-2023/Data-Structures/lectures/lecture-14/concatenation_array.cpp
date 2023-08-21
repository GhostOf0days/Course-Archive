vector<int> operator+(vector<int>& A, vector<int>& B){
    A.insert(A.end(), B.begin(), B.end());
    return A;
}

class Solution {
public:

    vector<int> getConcatenation(vector<int>& nums) {
        // fancy/crazy solution
        vector vec(nums);
        return vec+nums;
        
        /*
        // normal solution:
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        return ans;
        */
    }
};
