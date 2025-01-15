# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int i=0, j=arr.size()-1;
        while(i!=j){
            if( arr[i] + arr[j]==target) break;
            else if( arr[i] + arr[j]>target) j--;
            else i++;
        }
        vector<int> ans;
        ans.push_back(i+1);
        ans.push_back(j+1);
        return ans;
    }
};