# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:
    
    int solveRecursion(string &s, string &t, int i, int j,int &ns, int &nt){
        if(j==nt) return 1;
        if(i==ns) return 0;
        int ans=0;
        if(s[i]==t[j]){
            ans+=solveRecursion(s,t,i+1,j+1,ns,nt);
        }
        ans+=solveRecursion(s,t,i+1,j,ns,nt);
        return ans;
    }

    int solveMemo(string &s, string &t, int i, int j,int &ns, int &nt,  vector<vector<int>> &dp){
        if(j==nt) return 1;
        if(i==ns) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==t[j]){
            ans+=solveMemo(s,t,i+1,j+1,ns,nt,dp);
        }
        ans+=solveMemo(s,t,i+1,j,ns,nt,dp);
        dp[i][j]=ans;
        return dp[i][j];
    }

    int solveTab(string &s, string &t, int &ns, int &nt){
        vector<vector<int>>dp(ns+1,vector<int>(nt+1,0));
        //We will have to imitialize all the nt with ones according to the  base cases
        for(int i=0;i<=ns;i++){
            dp[i][nt]=1;
        }
        for(int i=ns-1;i>=0;i--){
            for(int j=nt-1;j>=0;j--){
                long long int ans=0;
                if(s[i]==t[j]){
                    ans+=dp[i+1][j+1];
                }
                ans+=dp[i+1][j];
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }

    
    int numDistinct(string s, string t) {
        int ns=s.length();
        int nt=t.length();
        // vector<vector<int>>dp(ns+1,vector<int>(nt+1,-1));
        return solveTab(s, t, ns, nt);
    }
};