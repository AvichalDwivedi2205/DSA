# include<iostream>
# include <vector>
using namespace std;

class Solution {
  public:
  
    int solveUsingRecursion(int n, int k){
        if(n==1) return k;
        if(n==2) return k*k;
        int ans = (solveUsingRecursion(n-1,k) + solveUsingRecursion(n-2,k))*(k-1);
        return ans;
    }
    
    int solveMem(int &n, int &k, vector <int> &dp){
        if(n==1) return k;
        if(n==2) return k*k;
        if(dp[n]!=-1) return dp[n];
        dp[n] = (solveUsingRecursion(n-1,k) + solveUsingRecursion(n-2,k))*(k-1);
        return dp[n];
    }
    
    int solveTabulation(int n, int k){
        vector<int> dp(n+1, -1);
        dp[1]=k;
        dp[2]=k*k;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])*(k-1);
        }
        return dp[n];
    }
    
    int SpaceOptimized(int n, int k){
        if(n==1) return k;
        if(n==2) return k*k;
        int prev=k;
        int curr=k*k;
        int ans=0;
        for(int i=3; i<=n; i++){
            ans=(prev+curr)*(k-1);
            prev=curr;
            curr=ans;
        }
        return ans;
    }
  
    int countWays(int n, int k) {
        // code here
        vector <int> dp(n+1, -1);
        return SpaceOptimized(n,k);
    }
};