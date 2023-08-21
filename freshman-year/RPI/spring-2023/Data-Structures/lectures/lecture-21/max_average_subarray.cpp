// O(n) solution
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max = INT_MIN;
        int low = 0;
        int high = 0;
        double sum = 0;
        double average = 0;
        int size = nums.size();
        // nums = [1,12,-5,-6,50,3], k = 4
        // traverse the vector
        while(high<size){
            sum += nums[high];  // high==0, sum += 1; sum==1; 
                                // high==1, sum += 12; sum == 13;
                                // high==2, sum += -5; sum == 8;
                                // high==3, sum += -6; sum == -2;
            // keep the size of k
            if(high-low+1==k){  // high==3, low==0; high-low+1==4==k;
                average = sum/k;
                if(average>max){
                    max = average;
                }
                sum -= nums[low];
                low++;
            }
            // increasing the size of the window.
            high++; // high == 1; high == 2;
        }
        return max;
    }
};
