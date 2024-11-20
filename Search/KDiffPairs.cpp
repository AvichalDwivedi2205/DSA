# include <vector>
# include <set>
# include <algorithm>
using namespace std;

class Solution {
public:

    //Best Approach
    int twoPointer(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;
        int i=0,j=1;
        while(j<nums.size()){
            int diff = nums[j]-nums[i];
            if(diff==k){
                ans.insert({nums[i], nums[j]});
                i++;
                j++;
            }else if(diff>k)
            i++;
            else
            j++;
            if(i==j)
            j++;
        }
        return ans.size();
    }

    //Second Best Approach
    int binarySearch(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());
    set<pair<int, int>> answer;

    for(int i = 0; i < nums.size() - 1; i++) {
        int s = i + 1, e = nums.size() - 1;
        int target = nums[i] + k;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                answer.insert({nums[i], nums[mid]});
                break;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
    }
    return answer.size();
}


    int findPairs(vector<int>& nums, int k) {
        return twoPointer(nums, k);
    }
};