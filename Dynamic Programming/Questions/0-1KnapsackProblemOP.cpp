# include<iostream>
# include <vector>
using namespace std;

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    
    int solveRecursion(int capacity, vector<int> &wt, vector<int> &val, int index, int n){
            // base case
        if(index>=n){
            return 0;
        }    
        // Inclusion and exclusion principal
        int include=0;
        if(wt[index]<=capacity){
            include=val[index]+solveRecursion(capacity-wt[index], wt, val, index+1, n);
        }
        int exclude=-0+solveRecursion(capacity, wt, val, index+1, n);
        int ans=max(include, exclude);
        return ans;
    }
    
    int solveMem(int capacity, vector<int> &wt, vector<int> &val, int index, int n,  vector<vector<int>> &dp){
       //base case
       if(index>=n){
            return 0;
        }    
        //Store it in dp array 
        if(dp[capacity][index]!=-1) return dp[capacity][index];
        // Inclusion and exclusion principal
        int include=0;
        if(wt[index]<=capacity){
            include=val[index]+solveMem(capacity-wt[index], wt, val, index+1, n, dp);
        }
        int exclude=-0+solveMem(capacity, wt, val, index+1, n, dp);
        dp[capacity][index]=max(include, exclude);
        return dp[capacity][index];
        
    }
    
    int solveTab(int capacity, vector<int> &wt, vector<int> &val, int n){
        vector<vector<int>> dp(capacity+1, vector<int>(n+1,-1));
        // We were returning zero when the nth index was greater than or equal to zero in the recursive case
        // So over here we are going to initialize all the nth index to 0
        for(int i=0;i<=capacity;i++){
            dp[i][n]=0;
        }
        // Now we will have to write the for loop 
        //We will have 2 for loops as we have 2 variables in this case
        for(int i=0;i<=capacity;i++){
            // In memoization approach capacity is moving from capacity to see so here it will be opposite
            // We are doing this as we are starting from j=n as seen from the base case
            for(int j=n-1;j>=0;j--){
                // In memoization we are returning when index is greater than n that is we are moving from 0 to n
                // So in case of tabulation we will move from n to 0
                // Since n was base base case and has already been calculated so we will not be finding n again
                // We will therefore start from n-1 instead
                int include=0;
                if(wt[j]<=i){
                    include=val[j]+dp[i-wt[j]][j+1];
                }
                int exclude=0+dp[i][j+1];
                dp[i][j]=max(include, exclude);
            }
        }
        return dp[capacity][0];
    }
    
    int SpaceOptimized(int capacity, vector<int> &wt, vector<int> &val, int n) {
        // We use two 1D arrays: `next` for the next item and `curr` for the current item
        vector<int> next(capacity + 1, 0);
        vector<int> curr(capacity + 1, -1);
    
        // Iterate over items in reverse order
        // Important: In the space-optimized approach, the capacity loop (i) must run in reverse (from capacity to 0).
        // This prevents overwriting values in the current row (curr) that are still needed for dependent calculations.
        // In contrast, the tabulation approach uses a 2D array and does not require reversing the capacity loop.
        // Aasan shabdo mein, we were builf=ding answer row wise in case of tabulation approach
        // In case of the space optimized approach we are building the answer colpumn wise so we need to reverse the loops over here.
        for (int j = n - 1; j >= 0; j--) {
            for (int i = 0; i <= capacity; i++) { // Iterate capacities in reverse order
                int include = 0;
                if (wt[j] <= i) {
                    include = val[j] + next[i - wt[j]]; // Include current item
                }
                int exclude = next[i]; // Exclude current item
                curr[i] = max(include, exclude); // Update current value
            }
            next = curr; // Shift `curr` to `next` for the next iteration
        }
        return curr[capacity]; // Final answer is in `next` after processing all items
    }
    
    int SpaceOptimizedEvenMore(int capacity, vector<int> &wt, vector<int> &val, int n) {
        // We use one array now
        //This is because i and i-wt[j] will surely lie within 0 to i
        //Because of this we can store the answer in the array itself as well
        // But we will need to go from capacity to 0 instead of 0 to capacity
        vector<int> next(capacity + 1, 0);
    
        for (int j = n - 1; j >= 0; j--) {
            for (int i = capacity; i >= 0; i--) { // Iterate capacities in reverse order
                int include = 0;
                if (wt[j] <= i) {
                    include = val[j] + next[i - wt[j]]; // Include current item
                }
                int exclude = next[i]; // Exclude current item
                next[i] = max(include, exclude); // Update current value
            }
        }
        return next[capacity]; // Final answer is in `next` after processing all items
    }

    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        return SpaceOptimized(capacity, wt, val, wt.size());
    }
};