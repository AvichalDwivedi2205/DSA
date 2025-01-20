# include<iostream>
# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:

    bool solveAnother(string &s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); // Convert wordDict to a set for O(1) lookups
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case: empty string can be segmented

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    bool checkWord(string &word, vector<string>& wordDict){
        for(auto w:wordDict){
            if(w==word)
            return true;
        }
        return false;
    }

    bool solveRecursion(string &s, vector<string>& wordDict, int start, int &n){
        if(start==n) return true;
        // One case making strings
        string word="";
        bool flag=false;
        for(int i=start;i<n;i++){
            word+=s[i];
            if(checkWord(word, wordDict)){
                flag=flag||solveRecursion(s, wordDict, i+1, n);
            }
        }
        return flag;
    }

    bool solveMemo(string &s, vector<string>& wordDict, int start, int &n, vector<short> &dp){
        if(start==n) return true;
        if(dp[start]!=-1) return dp[start];
        // One case making strings
        string word="";
        bool flag=false;
        for(int i=start;i<n;i++){
            word+=s[i];
            if(checkWord(word, wordDict)){
                flag=flag||solveMemo(s, wordDict, i+1, n, dp);
            }
        }
        dp[start]=flag;
        return dp[start];
    }

    bool solveTab(string &s, vector<string>& wordDict, int &n){
        vector<short> dp(n+1,1);
        for(int start=n-1;start>=0;start--){
            // One case making strings
            string word="";
            bool flag=false;
            for(int i=start;i<n;i++){
                word+=s[i];
                if(checkWord(word, wordDict)){
                    flag=flag||dp[i+1];
                }
            }
            dp[start]=flag;
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<short> dp(n+1,-1);
        return solveTab(s, wordDict, n);
    }
};