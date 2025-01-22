# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:

    int solveRecursion(vector<int> &piles, int i, int M, bool alice, int &n){
        if(i==n) return 0;
        int ans=alice?INT_MIN:INT_MAX;
        int total=0;
        for(int X=1;X<=2*M;X++){
            if(X+i-1>=n) break;
            total+=piles[X+i-1];
            if(alice){
                ans=max(ans, total+solveRecursion(piles, i+X, max(X,M), !alice, n));
            }else{
                ans=min(ans,solveRecursion(piles, i+X, max(X,M), !alice, n));
            }
        }
        return ans;
    }

    int solveMemo(vector<int> &piles, int i, int M, bool alice, int &n,  vector<vector<vector<int>>>&dp){
        if(i==n) return 0;
        if(dp[i][M][alice]!=-1) return dp[i][M][alice];
        int ans=alice?INT_MIN:INT_MAX;
        int total=0;
        for(int X=1;X<=2*M;X++){
            if(X+i-1>=n) break;
            total+=piles[X+i-1];
            if(alice){
                ans=max(ans, total+solveMemo(piles, i+X, max(X,M), !alice, n, dp));
            }else{
                ans=min(ans,solveMemo(piles, i+X, max(X,M), !alice, n, dp));
            }
        }
        return dp[i][M][alice]=ans;
    }

    int solveTab(vector<int> &piles, int &n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int M = n; M >= 1; M--) {  // M is constrained to be at most n
                for (int alice = 0; alice <= 1; alice++) {
                    int ans = alice ? INT_MIN : INT_MAX;
                    int total = 0;
                    for (int X = 1; X <= 2 * M; X++) {  // 2 * M is safe since M <= n
                        if (X + i - 1 >= n) break;
                        total += piles[X + i - 1];
                        if (alice) {
                            ans = max(ans, total + dp[i + X][max(X, M)][!alice]);
                        } else {
                            ans = min(ans, dp[i + X][max(X, M)][!alice]);
                        }
                    }
                    dp[i][M][alice] = ans;  // Save the computed result in dp table
                }
            }
        }
        return dp[0][1][1];
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        return solveTab(piles, n);
    }

};