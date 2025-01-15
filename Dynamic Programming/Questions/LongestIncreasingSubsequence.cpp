# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:

    int solveRecursion(vector<int>& nums, int prev, int curr){
        //Base Case
        if(curr>=nums.size()) return 0;

        // Solve One Case
        //Baaki Recursion Sambhal lega
        int include=0;
        if(prev==-1 || nums[curr]>nums[prev]) include=1+solveRecursion(nums, curr, curr+1);
        //We will be updating the previous value as current 
        int exclude=0+solveRecursion(nums, prev, curr+1);
        //In exclude prev nahi badhega as it is already included
        int ans=max(include, exclude);
        return ans;
    }

    int solveMemo(vector<int>& nums, int prev, int curr, vector<vector<int>>& dp){
        //Base Case
        if(curr>=nums.size()) return 0;

        // Solve One Case
        //Baaki Recursion Sambhal lega
        //Storing value in dp
        if(dp[curr][prev+1]!=0) return dp[curr][prev+1];
        int include=0;
        if(prev==-1 || nums[curr]>nums[prev]) include=1+solveMemo(nums, curr, curr+1, dp);
        //We will be updating the previous value as current 
        int exclude=0+solveMemo(nums, prev, curr+1, dp);
        //In exclude prev nahi badhega as it is already included
        dp[curr][prev+1]=max(include, exclude);
        return dp[curr][prev+1];
    }
    
     int solveTab(vector<int>& nums, int prev, int curr){
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // Analyzing the base case we had to imitialize the nth row of prev and curr with 0 so we already did that ny initializing with zero in the first step itself
        //We are going till n-1 as n is already done for
        for(int curr=n-1;curr>=0;curr--){// we are going from n to 1 as in the first approach we went from 1 to n
            for(int prev=curr-1;prev>=-1;prev--){// prev went from -1 to n-1 so go from curr-1 to -1
                int include=0;
                if (prev == -1 || nums[curr] > nums[prev]) 
                include = 1 + dp[curr+1][curr+
                1];
                //We will be updating the previous value as current 
                //Here we are doing +1 as we have to shift as we do not want prev=-1 to be here
                int exclude=0+dp[curr+1][prev+1];
                //In exclude prev nahi badhega as it is already included
                dp[curr][prev+1]=max(include, exclude);
            }
        }
        //Since we are sending -1 in prev so we have to return prev+1 as -1+1
        return dp[0][-1+1];
    }

    int solveUsingBS(vector<int> &nums){
        vector<int>ans;
        //initial state
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                //Just Bada Number exist karta hai
                //Iterator-beginning gives index
                //We can apply binary search here as in the answer all the elements are sorted
                int index=lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                //Replace
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }

    int SpaceOptimized(vector<int>& nums, int prev, int curr){
        int n=nums.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        // Analyzing the base case we had to imitialize the nth row of prev and curr with 0 so we already did that ny initializing with zero in the first step itself
        //We are going till n-1 as n is already done for
        for(int curr=n-1;curr>=0;curr--){// we are going from n to 1 as in the first approach we went from 1 to n
            for(int prev=curr-1;prev>=-1;prev--){// prev went from -1 to n-1 so go from curr-1 to -1
                int include=0;
                if (prev == -1 || nums[curr] > nums[prev]) 
                include = 1 + nextRow[curr + 1];
                //We will be updating the previous value as current 
                //Here we are doing +1 as we have to shift as we do not want prev=-1 to be here
                int exclude=0+nextRow[prev+1];
                //In exclude prev nahi badhega as it is already included
                currRow[prev+1]=max(include, exclude);
            }
            //Shifting
            nextRow=currRow;
        }
        //Since we are sending -1 in prev so we have to return prev+1 as -1+1
        return nextRow[0]; 
    }

    //Final Solution Is Binary Search Crazy Ass Shit


    int lengthOfLIS(vector<int>& nums) {
        // We can include only when the last number will be less than the previous one.
        // This is also based on the priciple of exclusion and inclusion
        // When the next number is greater then include or else exclude
        return solveUsingBS(nums);
    }
};
