# include<iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:

    int solveRecursion(int n) {
        if (n == 0) return 0; // 0 requires 0 perfect squares.
        if (n < 0) return INT_MAX; // Base case to avoid invalid results.

        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while (i <= end) {
            ans=min(ans, 1+solveRecursion(n-i*i));
            i++;
        }
        return ans;
    }

    int solveMemo(int n, vector<int> &dp){
        if (n == 0) return 1; // 0 requires 0 perfect squares.
        if (n < 0) return 0; // Base case to avoid invalid results.
        if(dp[n]!=-1) return dp[n];
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while (i <= end) {
            ans=min(ans, 1+solveMemo(n-i*i, dp));
            i++;
        }
        dp[n]=ans;
        return dp[n];
    }

    int solveTab(int &n){
        // if (n == 0) return 1; // 0 requires 0 perfect squares.
        // if (n < 0) return 0; // Base case to avoid invalid results.
        vector<int> dp(n+1, 0);
        dp[0]=1;
        for(int i=1; i<=n; i++){
            int ans = INT_MAX;
            int s = 1;
            int end = sqrt(i);
            while (s <= end) {
                ans=min(ans, 1+dp[i-s*s]);
                s++;
            }
            dp[i]=ans;
        }
        return dp[n];
    }

    int numSquares(int n) {
        return solveTab(n)-1; // No need to subtract 1.
    }
};
