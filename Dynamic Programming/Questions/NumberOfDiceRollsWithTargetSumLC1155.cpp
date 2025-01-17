# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:

    long long int MODval = 1e9+7;

    int solveRecursion(int n, int &k, int target) {
        if (target == 0 && n == 0) {
            return 1; // Valid way
        }
        if (target != 0 && n == 0) {
            return 0; // Invalid way
        }
        if (target == 0 && n != 0) {
            return 0; // Invalid way
        }

        int ans = 0;

        for (int i = 1; i <= k; i++) {
            int recAns=0; // Dice rolls are from 1 to k
            if (target - i >= 0) {
                int recAns = solveRecursion(n - 1, k, target - i) % MODval;
                ans = (ans % MODval + recAns % MODval) % MODval;
            }
        }

        return ans;
    }

    int solveMem(int n, int &k, int target, vector<vector<int>> &dp) {
        if (target == 0 && n == 0) {
            return 1; // Valid way
        }
        if (target != 0 && n == 0) {
            return 0; // Invalid way
        }
        if (target == 0 && n != 0) {
            return 0; // Invalid way
        }
        if (dp[n][target] != -1) return dp[n][target];

        int ans = 0;
        for (int i = 1; i <= k; i++) { // Dice rolls are from 1 to k
            int recAns=0;
            if (target - i >= 0) {
                recAns = solveMem(n - 1, k, target - i, dp) % MODval;
            }
            ans = (ans % MODval + recAns % MODval) % MODval;
        }
        dp[n][target] = ans;
        return dp[n][target];
    }

    int solveTab(int &n, int &k, int &target){
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0]=1;
        int ans=0;
        for(int dice=1;dice<=n;dice++){
            for(int j=1;j<=target;j++){
                int ans=0;
                for(int i=1;i<=k;i++){
                    int recAns=0;
                    if(j-i>=0){
                        recAns=dp[dice-1][j-i]%MODval;
                    }
                    ans = (ans % MODval + recAns % MODval) % MODval;
                }
                dp[dice][j]=ans;
            }
        }
        return dp[n][target];
    }

    int solveTabBetter(int &n, int &k, int &target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base case: 1 way to achieve target 0 with 0 dice
        dp[0][0] = 1;

        // Fill the DP table
        for (int dice = 1; dice <= n; dice++) {
            for (int t = 1; t <= target; t++) {
                int ans = 0;
                for (int roll = 1; roll <= min(t, k); roll++) {
                    ans = (ans + dp[dice - 1][t - roll]) % MODval;
                }
                dp[dice][t] = ans;
            }
        }

        return dp[n][target];
    }

    int SpaceOptimized(int &n, int &k, int &target) {
        vector<int> prev(target + 1, 0); // Previous row
        vector<int> curr(target + 1, 0); // Current row

        // Base case: 1 way to achieve target 0 with 0 dice
        prev[0] = 1;

        for (int dice = 1; dice <= n; dice++) {
            for (int t = 0; t <= target; t++) {
                curr[t] = 0; // Reset current cell
                for (int roll = 1; roll <= min(t, k); roll++) {
                    curr[t] = (curr[t] + prev[t - roll]) % MODval;
                }
            }
            // Move to the next row: curr becomes prev
            prev = curr;
        }

        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return SpaceOptimized(n, k, target);
    }

};