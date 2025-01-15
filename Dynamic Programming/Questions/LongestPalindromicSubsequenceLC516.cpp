// We can also do it using other methods of longest common subsequence as well 
// Those methods are tabulation, recursiva and memoization

# include<iostream>
# include <vector>
using namespace std;

class Solution {
public:

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

    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        int ans = SpaceOptimizedEvenMore(s,r);
        return ans;
    }
};