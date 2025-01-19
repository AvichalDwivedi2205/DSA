# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int maxLen=1, start=0;
    bool recursivePalindrome(string&str, int s, int e){
        if(s>=e) return true;
        bool flag=false;

        if(str[s]==str[e]){
            flag=recursivePalindrome(str, s+1, e-1);
        }
        if(flag){
            int currLen=e-s+1;
            if(currLen>maxLen){
                maxLen=currLen;
                start=s; 
            }
        }
        return flag;
    }

    bool solveMemo(string&str, int s, int e, vector<vector<int>> &dp){
        if(s>=e) return true;
        bool flag=false;
        if(dp[s][e]!=-1) return dp[s][e];
        if(str[s]==str[e]){
            flag=solveMemo(str, s+1, e-1, dp);
        }
        if(flag){
            int currLen=e-s+1;
            if(currLen>maxLen){
                maxLen=currLen;
                start=s; 
            }
        }
        dp[s][e]=flag;
        return dp[s][e];
    }

    bool isPalindrome(string&str, int s, int e){
        while(s<e){
            if(str[s]!=str[e])
            return false;
            s++;
            e--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //Looping Method which I though of
        // int longest=1;
        // pair<int, int> index;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(isPalindrome(s, i, j)){
        //             int newlong=max(j-i+1, longest);
        //             if(newlong>longest){
        //                 index.first=i;
        //                 index.second=j;
        //             }
        //             longest=newlong;
        //         }else{
        //             continue;
        //         }
        //     }
        // }
        // return s.substr(index.first, index.second-index.first+1);

        for(int i=0; i<n; i++){
            for(int j=0;j<n;j++){
                bool t = solveMemo(s,i,j,dp);
            }
        }
        return s.substr(start, maxLen);
    }
};