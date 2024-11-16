#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int prefixSumApproach(vector<int>& nums){
        int n = nums.size();
        vector<int> leftsum(nums.size(), 0);
        vector<int> rightsum(nums.size(), 0);

        for(int i=1;i<n;i++){
            leftsum[i] = nums[i-1] + leftsum[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rightsum[i] = nums[i+1] + rightsum[i+1];
        }
        for(int i=0;i<n;i++){
            if(leftsum[i]==rightsum[i])
            return i;
        }
        return -1;
    }
     
    int pivotIndex(vector<int>& nums) {
        return prefixSumApproach(nums);
}
};