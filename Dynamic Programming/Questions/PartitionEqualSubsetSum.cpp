# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:

    bool solveRecursion(vector<int>& nums, int index, int currSum, int &target, int &n){
        if(index>=n) return false;
        if(currSum>target) return false;
        if(currSum==target) return true;
        bool include=solveRecursion(nums, index+1, currSum+nums[index], target, n);
        bool exclude=solveRecursion(nums, index+1, currSum, target, n);
        return include||exclude;
    }

    bool solveMemo(vector<int>& nums, int index, int currSum, int &target, int &n, vector<vector<short>> &dp){
        if(index>=n) return false;
        if(currSum>target) return false;
        if(currSum==target) return true;
        if(dp[index][currSum]!=2) return dp[index][currSum];
        bool include=solveMemo(nums, index+1, currSum+nums[index], target, n, dp);
        bool exclude=solveMemo(nums, index+1, currSum, target, n, dp);
        dp[index][currSum] = include||exclude;
        return dp[index][currSum];
    }   

    bool solveTab(vector<int>& nums, int &target, int &n){
        vector<vector<short>>dp(n+2, vector<short>(target+1,0));
        //We are imitializing it with zero because of base case
        // Analyze the base case it says that whenever sum=target then it is one so we will mark one there
        for(int i=0;i<=n;i++){
            dp[i][target]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int sum=target;sum>=0;sum--){
                bool include=0;
                if(sum+nums[i]<=target)
                include=dp[i+1][sum+nums[i]];
                bool exclude=dp[i+1][sum];
                dp[i][sum] = include||exclude;
            }
        }
        return dp[0][0];
    }

    bool SpaceOptimized(vector<int>& nums, int &target, int &n){
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);
        //This is the base case of the following
        curr[target]=1;
        next[target]=1;
         for(int i=n-1;i>=0;i--){
            for(int sum=target;sum>=0;sum--){
                bool include=0;
                if(sum+nums[i]<=target)
                include=next[sum+nums[i]];
                bool exclude=next[sum];
                curr[sum] = include||exclude;
            }
            next=curr;
        }
        return next[0];
    }

    bool canPartition(vector<int>& nums) {
        int index=0;
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        //We cannot partition in case of an odd
        //So we will just return false in this case
        if(sum & 1) return false;
        int target=sum/2;
        int n=nums.size();
        // vector<vector<short>>dp(n+1, vector<short>(target+1,2));
        return SpaceOptimized(nums, target, n);
    }
};