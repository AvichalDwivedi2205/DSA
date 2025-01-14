# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:

    int solveRecursion(string &text1, string &text2, int i1, int i2){
        if(i1>=text1.length()) return 0;
        if(i2>=text2.length()) return 0;

        //Solve 1 Case 
        //Baaki Recusion Karlega
        int ans=0;
        if(text1[i1]==text2[i2]){
            ans=1+solveRecursion(text1, text2, i1+1, i2+1);
        }else{
            ans=0+max(solveRecursion(text1, text2, i1, i2+1),solveRecursion(text1, text2, i1+1, i2));
        }
        return ans;
    }

    int solveMemo(string &text1, string &text2, int i1, int i2, vector<vector<int>> &dp){
        if(i1>=text1.length()) return 0;
        if(i2>=text2.length()) return 0;

        //Solve 1 Case 
        //Baaki Recusion Karlega
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        int ans=0;
        if(text1[i1]==text2[i2]){
            ans=1+solveMemo(text1, text2, i1+1, i2+1, dp);
        }else{
            ans=0+max(solveMemo(text1, text2, i1, i2+1, dp),solveMemo(text1, text2, i1+1, i2, dp));
        }
        dp[i1][i2]=ans;
        return dp[i1][i2];
    }

    int solveTab(string &text1, string &text2){
        // If length of any is zero then we will have no common subsequence
        if(text1.length()==0) return 0;
        if(text2.length()==0) return 0;
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1,0));
        //Let us now analyze the base cases
        //We need to insert all with zero for row=text1.length and col=text1.length
        // That iswhy we are initializing with zero in the start only 
        //Why take BT
        // Idhar loop ulta chalega as in memoization
        //We need to start from a.length-1 here as a.length is already taken care of
        for(int i=text1.length()-1; i>=0; i--){
            for(int j=text2.length()-1; j>=0; j--){
                int ans=0;
                if(text1[i]==text2[j]){
                    ans=1+dp[i+1][j+1];
                }else{
                    ans=0+max(dp[i][j+1], dp[i+1][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }

    int SpaceOptimized(string &text1, string &text2){
        vector<int> curr(text1.length()+1, 0);
        vector<int> next(text1.length()+1, 0);
        //Here we had to take text1.length() as we want no. of blocks in a column which is no. of rows
        for(int j=text2.length()-1; j>=0;j--){
            for(int i=text1.length()-1;i>=0;i--){
                int ans=0;
                if(text2[j]==text1[i]){
                    ans=1+next[i+1];
                }else{
                    ans=0+max(next[i], curr[i+1]);
                }
                curr[i]=ans;
            }
            //shifting
            next=curr;
        }
        return curr[0];
    }

    int SpaceOptimizedEvenMore(string &text1, string &text2) {
        vector<int> prev(text1.length() + 1, 0);

        for (int j = text2.length() - 1; j >= 0; j--) {
            int diagonal = 0; // Tracks the value of next[i+1] from the previous row.
            for (int i = text1.length() - 1; i >= 0; i--) {
                int temp = prev[i]; // Temporarily store the value before overwriting.
                if (text2[j] == text1[i]) {
                    prev[i] = 1 + diagonal;
                } else {
                    prev[i] = max(prev[i], prev[i + 1]);
                }
                diagonal = temp; // Update diagonal for the next iteration.
            }
        }
        return prev[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1,-1));
        return SpaceOptimizedEvenMore(text1, text2);
    }
};