# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:

    int recursive(int n){
         // base case
        if(n==0 || n==1){
            return n;
        }
        int ans=fib(n-1)+fib(n-2);
        return ans;
    }

    int solveUsingMem(int n, vector<int> &dp){
         if(n==0 || n==1){
            return n;
        }
        //If answer already exists then return the answer
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n]=solveUsingMem(n-1, dp)+solveUsingMem(n-2, dp);
        return dp[n];
    }

    int solveUsingTabulation(int n, vector<int> &dp){
        if(n==0 || n==1){
            return n;
        }
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    
    int loopMethod(int n){
        if(n==0 || n==1){
            return n;
        }
        int first=0;
        int second=1;
        int ans=0;
        for(int i=2;i<=n;i++){
            ans=first+second;
            first=second;
            second=ans;
        }
        return ans;
    }

    int fib(int n) {
        //create dp array
        return loopMethod(n);
    }
};