# include<iostream>
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:

    vector<string> solve(string &s, unordered_map<string, bool> &mp, int i, int &n){
        if(i==n) return {""};
        vector<string> ans;
        string word="";
        for(int j=i;j<n;j++){
            word.push_back(s[j]);
            if(mp.find(word)==mp.end()) continue;
            auto right = solve(s,mp,j+1,n);
            for(auto eachRightPart:right){
                string endPart;
                if(eachRightPart.length()>0) endPart=" "+eachRightPart;
                ans.push_back(word + endPart);
            }
        }
        return ans;
    }

    vector<string> solveMemo(string &s, unordered_map<string, bool> &mp, int i, int &n, unordered_map<int, vector<string>> &dp){
        if(i==n) return {""};
        if(dp.find(i)!=dp.end()) return dp[i];
        vector<string> ans;
        string word="";
        for(int j=i;j<n;j++){
            word.push_back(s[j]);
            if(mp.find(word)==mp.end()) continue;
            auto right = solveMemo(s,mp,j+1,n,dp);
            for(auto eachRightPart:right){
                string endPart;
                if(eachRightPart.length()>0) endPart=" "+eachRightPart;
                ans.push_back(word + endPart);
            }
        }
        dp[i]=ans;
        return dp[i];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        unordered_map<int, vector<string>> dp;
        for(auto word: wordDict){
            mp[word]=1;
        }
        int n=s.size();
        return solveMemo(s, mp, 0, n, dp);
    }
};