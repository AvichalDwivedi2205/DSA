# include<iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:

    int solveByRecursion(string &s1, string &s2, int i1, int i2, int &lens1, int &lens2){
        if(i1>=lens1){
            int sum=0;
            for( int i=i2; i<lens2; i++)
            sum+=s2[i];
            return sum;
        }
        if(i2>=lens2){
            int sum=0;
            for( int i=i1; i<lens1; i++)
            sum+=s1[i];
            return sum;
        }
        int include=0;
        if(s1[i1]==s2[i2]){
            return solveByRecursion(s1,s2,i1+1,i2+1,lens1,lens2);
        }
        int exclude1=s1[i1]+solveByRecursion(s1,s2,i1+1,i2,lens1,lens2);
        int exclude2=s2[i2]+solveByRecursion(s1,s2,i1,i2+1,lens1,lens2);
        return min(exclude1, exclude2);
    }

    int solveMemo(string &s1, string &s2, int i1, int i2, int &lens1, int &lens2, vector<vector<int>> &dp){
         if(i1>=lens1){
            int sum=0;
            for( int i=i2; i<lens2; i++)
            sum+=s2[i];
            return sum;
        }
        if(i2>=lens2){
            int sum=0;
            for( int i=i1; i<lens1; i++)
            sum+=s1[i];
            return sum;
        }
        if(dp[i1][i2]!=0) return dp[i1][i2];
        int include=0;
        if(s1[i1]==s2[i2]){
            dp[i1][i2] = solveMemo(s1,s2,i1+1,i2+1,lens1,lens2,dp);
            return dp[i1][i2];
        }
        int exclude1=s1[i1]+solveMemo(s1,s2,i1+1,i2,lens1,lens2,dp);
        int exclude2=s2[i2]+solveMemo(s1,s2,i1,i2+1,lens1,lens2,dp);
        dp[i1][i2] = min(exclude1, exclude2);
        return dp[i1][i2];
    }

    int solveTab(string &s1, string &s2, int &len1, int &len2, vector<vector<int>> &dp){
        long long int sums1=0;
        long long int sums2=0;
        for(int i=0;i<len1;i++){
            sums1+=s1[i];
        }
        for(int i=0;i<len2;i++){
            sums2+=s2[i];
        }
        dp[len1][0]=sums2;
        dp[0][len2]=sums1;
        for(int i=1;i<len1;i++){
            if(sums1>0){
                sums1=sums1-s1[i-1];
                dp[i][len2]=sums1;
            }else{
                break;
            }
        }
        for(int i=1;i<len2;i++){
            if(sums2>0){
                sums2=sums2-s2[i-1];
                dp[len1][i]=sums2;
            }else{
                break;
            }
        }
        for(int i1=len1-1;i1>=0;i1--){
            for(int i2=len2-1;i2>=0;i2--){
                int include=0;
                if(s1[i1]==s2[i2]){
                    dp[i1][i2]=dp[i1+1][i2+1];
                }else{
                    dp[i1][i2]=min(s1[i1]+dp[i1+1][i2], s2[i2]+dp[i1][i2+1]);
                }
            }
        }
        return dp[0][0];
    }

    int minimumDeleteSum(string s1, string s2) {
        int lens1=s1.length();
        int lens2=s2.length();
        vector<vector<int>> dp(lens1+1, vector<int> (lens2+1, 0));
        return solveTab(s1, s2, lens1, lens2, dp);
    }
};