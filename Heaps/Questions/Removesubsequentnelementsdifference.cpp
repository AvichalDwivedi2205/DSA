# include <iostream>
# include <queue>
using namespace std;

//Not anywhere on the platform
// This is LC 2163 but we can only remove subsequent n elements

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        // We can eaily do this by sliding window approach
        // Window will be from i to i+nums.size()/3 We will not take the sum of them
        // After that we will just store the min of each sum in each of the cases
        int minDiff=INT_MAX;
        int val=nums.size()/3;
        int sumLeft=0;
        int sumRight=0;
        for(int i=0; i<val; i++){
            sumLeft+=nums[val+i];
            sumRight+=nums[(2*val)+i];
        }
        minDiff = min(minDiff, sumLeft-sumRight);
        int prev=minDiff;
        for(int i=1; i<nums.size()-val+1; i++){
            if(i<=val){
                prev=prev+nums[i-1]-nums[val+i-1];
                minDiff=min(prev, minDiff);
            }else{
                prev=prev-nums[i-1]+nums[val+i-1];
                minDiff=min(prev, minDiff);
            }
        }
        return minDiff;
    }
};