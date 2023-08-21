// solution to leetcode 1876

class Solution {
public:
    // assume s has a length of 3
    bool isGood(string s, int low){
        if(s[low]==s[low+1] || s[low+1]==s[low+2] || s[low]==s[low+2]){
            return false;
        }else{
            return true;
        }
    }

    int countGoodSubstrings(string s) {
        int count = 0;
        int low = 0;
        int high = 2;
        int len = s.length();
        // traverse the whole string
        while(high<len){
            if(isGood(s, low)){
                count++;
            }
            // move the window
            high++;
            low++;
        }
        return count;
    }
};
