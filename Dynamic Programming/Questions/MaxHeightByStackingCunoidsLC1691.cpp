
# include<iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:

    bool check(vector<int> &curr, vector<int> &prev){
        //We are going from last row in the loop in spaceOptimized
        // So therefore we can say that current is representing the bigger dabba and prev is representing the smaller one
        // so ulta karna hoga
        if(curr[0]>=prev[0] && curr[1]>=prev[1] && curr[2]>=prev[2]){
            return true;
        }else{
            return false;
        }
    }

    //We cannot apply binary search code obver here as we cannot get the bigger cuboid than the porevious cuboid using binary search
    // SO this would be the most optimal approach in this case

    int SpaceOptimized(vector<vector<int>>& cuboids){
        int n=cuboids.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        // Analyzing the base case we had to imitialize the nth row of prev and curr with 0 so we already did that ny initializing with zero in the first step itself
        //We are going till n-1 as n is already done for
        for(int curr=n-1;curr>=0;curr--){// we are going from n to 1 as in the first approach we went from 1 to n
            for(int prev=curr-1;prev>=-1;prev--){// prev went from -1 to n-1 so go from curr-1 to -1
                int include=0;
                if (prev == -1 || check(cuboids[curr], cuboids[prev])) 
                include = cuboids[curr][2] + nextRow[curr + 1];
                //We will be updating the previous value as current 
                //Here we are doing +1 as we have to shift as we do not want prev=-1 to be here
                int exclude=0+nextRow[prev+1];
                //In exclude prev nahi badhega as it is already included
                currRow[prev+1]=max(include, exclude);
            }
            //Shifting
            nextRow=currRow;
        }
        //Since we are sending -1 in prev so we have to return prev+1 as -1+1
        return nextRow[0]; 
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid: cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        //First will have complexity of O(3nlog3)
        //Since we are sorting only 3 elements n times 
        sort(cuboids.begin(), cuboids.end());
        //Here the complexity will be nlogn as we are sorting n elements that is the first one
        //Now height ans the first row have been sorted 
        //Now we can apply the logic of longest increasing subsequence
        return SpaceOptimized(cuboids);
    }
};