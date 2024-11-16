#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int sortingApproach(vector<int>& nums){
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[i+1])
            return nums[i];
        }
        return 0;
    }
    
    int betterApproach(vector<int>& nums){
        int n=nums.size(), ans=-1;
        for(int i=0; i<n;i++){
            int index=abs(nums[i]);
            if(nums[index]<0){
                ans = index;
                break;
            }
            nums[index]*=-1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]<0)
            nums[i]*=-1;
        }
        return ans;
    }

    int PositioningMethod(vector<int>& nums){
        while(nums[0] != nums[nums[0]]){
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }

    int findDuplicate(vector<int>& nums) {
        return PositioningMethod(nums);
    }
};