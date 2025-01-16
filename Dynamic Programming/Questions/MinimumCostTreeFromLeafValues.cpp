# include<iostream>
# include <vector>
# include <map>
using namespace std;

class Solution {
public:

    int solveRecursion(vector<int>& arr, int s, int e, map<pair<int, int>, int> &mp) {
        if(s>e) return 0;
        if(s==e) return 0;
        // this is because if s==e then taht will be a leaf node so we will return 0 in that case as well
        //i is used for partitioning
        int ans = INT_MAX;
        for(int i=s;i<e;i++){
            ans = min(ans, mp[{s, i}] * mp[{i + 1, e}] + solveRecursion(arr, s, i, mp) + solveRecursion(arr, i + 1, e, mp));

        }
        return ans;
    }

    int solveMemo(vector<int>& arr, int s, int e, map<pair<int, int>, int> &mp, vector<vector<int>> &dp){
        if(s>e) return 0;
        if(s==e) return 0;
        // this is because if s==e then taht will be a leaf node so we will return 0 in that case as well
        //i is used for partitioning
        if(dp[s][e]!=0) return dp[s][e];
        int ans = INT_MAX;
        for(int i=s;i<e;i++){
            ans = min(ans, mp[{s, i}] * mp[{i + 1, e}] + solveMemo(arr, s, i, mp, dp) + solveMemo(arr, i + 1, e, mp, dp));
        }
        dp[s][e]=ans;
        return dp[s][e];
    }

    int solveTab(vector<int>& arr, map<pair<int, int>, int> &mp, int &n){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int s=n-1;s>=0;s--){
            for(int e=1;e<n;e++){
                if(s>=e) continue;
                int ans=INT_MAX;
                for(int i=s;i<e;i++){
                    ans=min(ans, mp[{s, i}] * mp[{i + 1, e}] + dp[s][i] + dp[i+1][e]);
                }
                dp[s][e]=ans;
            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        //We can just precompute the max of range
        //That is mapping of max from a certain value to that range
        int n=arr.size();
        map<pair<int, int>, int> mp;
        for(int i=0;i<n; i++){
            mp[{i, i}]=arr[i];
            for(int j=i+1; j<n;j++){
                mp[{i,j}]=max(arr[j], mp[{i,j-1}]);
            }
        }
        // int s=0,e=n-1;
        return solveTab(arr, mp, n);
    }
};