# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:

    int solveUsingRecursion(vector<int> &coins, int amount){
        // Base case
        if(amount==0) return 0;

        //Looping to get all the possible values
        int mini = INT_MAX;
        for(int i=0;i<coins.size(); i++){
            // Find Answer using ith coin
            //Call recursion only for valid amounts that is when it is greater than 0
            if(amount-coins[i]>=0){
                int recursionAns=solveUsingRecursion(coins, amount-coins[i]);
                //Check For INT_MAX if it retuens INT_MAX it means that mini hasnot been updated so no need to go any further
                if(recursionAns!=INT_MAX){
                    int ans = 1+recursionAns;
                    mini=min(ans, mini);
                }
            }
        }
        return mini; 
    }

    int solveUsingMem(vector<int> &coins, int amount, vector<int> &dp){
        // Base case
        if(amount==0) return 0;

        //If answer already exists
        if(dp[amount]!=-1) return dp[amount];

        //Looping to get all the possible values
        int mini = INT_MAX;
        for(int i=0;i<coins.size(); i++){
            // Find Answer using ith coin
            //Call recursion only for valid amounts that is when it is greater than 0
            if(amount-coins[i]>=0){
                int recursionAns=solveUsingMem(coins, amount-coins[i], dp);
                //Check For INT_MAX if it retuens INT_MAX it means that mini hasnot been updated so no need to go any further
                if(recursionAns!=INT_MAX){
                    int ans = 1+recursionAns;
                    mini=min(ans, mini);
                }
            }
        }
        dp[amount]=mini;
        return dp[amount]; 
    }
    
    int solveUsingTabulation(vector<int>& coins, int amount) {
        //step1: done
        int n = amount;
        vector<int> dp(n+1, INT_MAX);
        //step2: base case analyse
        dp[0] = 0;
        //for loop
        for( int value = 1; value<=amount; value++) {
            int mini = INT_MAX;
            for(int i=0; i<coins.size(); i++) {
            
                if(value - coins[i] >= 0) {
                    int recursionKaAns = dp[value - coins[i] ];
                    
                    if(recursionKaAns != INT_MAX) {
                        
                        int ans = 1 + recursionKaAns;
                        mini  = min(mini, ans);
                    }
                }
            }
            dp[value] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // int ans=solveUsingRecursion(coins, amount);
        // //If INT_MAX has been returned it means that the value does not even exist
        // if(ans==INT_MAX) return -1;
        // else return ans;
        int ans = solveUsingTabulation(coins, amount);
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};