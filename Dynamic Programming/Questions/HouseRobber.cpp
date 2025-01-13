# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:

    int robHelp(vector<int>& nums, int i) {
        if(i>nums.size()-1){
            return 0;
        }
        int rob1 = nums[i]+robHelp(nums, i+2);
        int rob2 = robHelp(nums, i+1);
        return max(rob1, rob2);
    }

    int solveUsingMem(vector<int> &nums, int i, vector<int> &dp){
        if(i>nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int rob1 = nums[i]+solveUsingMem(nums, i+2, dp);
        int rob2 = solveUsingMem(nums, i+1, dp);
        dp[i] = max(rob1, rob2);
        return dp[i];
    }

    int solveUsingTabulation(vector<int> &nums){
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[n-1]=nums[n-1];
        //In memoization code went from 0 to n so we will have opposite in tabulation
        //In tabulation it will be from n to 0
        for(int i=n-2;i>=0;i--){
            int tempAns=0;
            if(i+2<n) tempAns=dp[i+2];
            int include=nums[i] + tempAns;
            int exclude=0+dp[i+1];
            dp[i]=max(include, exclude);
        }
        return dp[0];
    }

    int SpaceOptimized(vector<int> &nums){
        int n=nums.size();
        int prev=nums[n-1];
        int next=0;
        int curr;
        for(int i=n-2; i>=0; i--){
            int tempAns=0;
            if(i+2<n) tempAns=next;
            int include=nums[i]+tempAns;
            int exclude=0+prev;
            curr=max(include, exclude);
            next=prev;
            prev=curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        return SpaceOptimized(nums);
    }
};