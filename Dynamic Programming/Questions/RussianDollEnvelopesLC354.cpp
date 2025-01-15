# include<iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:

    bool check(vector<int> &curr, vector<int> &prev){
        if(curr[0]>prev[0] && curr[1]>prev[1])
        return true;
        else 
        return false;
    }

    int SpaceOptimized(vector<vector<int>>& envelopes){
        int n=envelopes.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include=0;
                if(prev==-1 || check(envelopes[curr], envelopes[prev])){
                    include=1+nextRow[curr+1];
                }
                int exclude=0+nextRow[prev+1];
                currRow[prev+1]=max(include, exclude);
            }
            nextRow=currRow;
        }
        return nextRow[0];
    }
    int binarySearch(vector<vector<int>>& envelopes) {
        vector<int> ans;
        for (const auto& envelope : envelopes) {
            int height = envelope[1];
            auto it = lower_bound(ans.begin(), ans.end(), height);
            if (it == ans.end()) {
                ans.push_back(height); // Append if height is greater than all in ans
            } else {
                *it = height; // Replace the first element that is >= height
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort by width in ascending order, and by height in descending order for same width
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        // Perform binary search on the heights
        return binarySearch(envelopes);
    }


};