# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:

    int solveRecursion(int s, int e){
        //base case
        if(s>=e) {
            return 0;
        }
        int ans=INT_MAX;
        for(int i=s; i<=e; i++){
            ans=min(ans, i+max(solveRecursion(s,i-1), solveRecursion(i+1,e)));
        }
        return ans;
    }

    int solveMemo(int s, int e, vector<vector<int>> &dp){
         //base case
        if(s>=e) {
            return 0;
        }
        if(dp[s][e]!=0) return dp[s][e];
        int ans=INT_MAX;
        for(int i=s; i<e; i++){
            ans=min(ans, i+max(solveMemo(s,i-1,dp), solveMemo(i+1,e,dp)));
        }
        dp[s][e]=ans;
        return dp[s][e];
    }

    int solveTab(int &n){
        vector<vector<int>>dp(n+2, vector<int>(n+1, 0));
        //We are making it n+2 as we are accessing n+1 index in the loop
        for(int s=n-1;s>=1;s--){ // We are going from n to 1 because in casse of the last part we were using form 1 to n so we will go from n to 1 in this case
            for( int e=1;e<=n;e++){
                // Same ulta in case of e as well
                if(s>=e) continue;
                int ans =INT_MAX;
                for(int i=s;i<e;i++){
                    ans=min(ans,i+ max(dp[s][i-1], dp[i+1][e]));
                }
                dp[s][e]=ans;
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        return solveTab(n);
    } 
};