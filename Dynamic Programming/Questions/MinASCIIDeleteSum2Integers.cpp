# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:

    int solveRecursion(vector<int>& days, vector<int>& costs, int i){
        int n=days.size();
        // Base condition
        if(i>=n){
            return 0;
        }

        // solution for a case
        // 1 Day Pass Taken
        int cost1 = costs[0]+solveRecursion(days, costs, i+1);

        // 7 Day Pass Taken
        int passEndDay = days[i]+7-1;
        int j=i;
        while(j<n && days[j]<=passEndDay){
            j++;
        }
        int cost7 = costs[1]+solveRecursion(days, costs, j);

        // 30 Day Pass Token
        passEndDay = days[i]+30-1;
        j=i;
        while(j<n && days[j]<=passEndDay){
            j++;
        }
        int cost30 = costs[2]+solveRecursion(days, costs, j);
        return min(cost1, min(cost7, cost30));
    }

    int solveMem(vector<int>& days, vector<int>& costs, int i, vector<int> &dp, int &n){
        // Base condition
        if(i>=n){
            return 0;
        }
        if(dp[i]!=0) return dp[i];
        // solution for a case
        // 1 Day Pass Taken
        int cost1 = costs[0]+solveMem(days, costs, i+1, dp, n);

        // 7 Day Pass Taken
        int passEndDay = days[i]+7-1;
        int j=i;
        while(j<n && days[j]<=passEndDay){
            j++;
        }
        int cost7 = costs[1]+solveMem(days, costs, j, dp, n);

        // 30 Day Pass Token
        passEndDay = days[i]+30-1;
        j=i;
        while(j<n && days[j]<=passEndDay){
            j++;
        }
        int cost30 = costs[2]+solveMem(days, costs, j, dp, n);
        dp[i] = min(cost1, min(cost7, cost30));
        return dp[i];
    }

    int solveTab(vector<int>& days, vector<int>& costs, vector<int> &dp, int &n){
        for(int i=n-1;i>=0;i--){
            // 1 Day Pass Taken
            int cost1 = costs[0]+dp[i+1];

            // 7 Day Pass Taken
            int passEndDay = days[i]+7-1;
            int j=i;
            while(j<n && days[j]<=passEndDay){
                j++;
            }
            int cost7 = costs[1]+dp[j];

            // 30 Day Pass Token
            passEndDay = days[i]+30-1;
            j=i;
            while(j<n && days[j]<=passEndDay){
                j++;
            }
            int cost30 = costs[2]+dp[j];
            dp[i] = min(cost1, min(cost7, cost30));
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1, 0);
        return solveTab(days, costs, dp, n);
    }
};