#include <vector>
using namespace std;
class Solution {
public:
    int firstOccurence(vector<int>& arr, int target){
        int s=0,e=arr.size()-1,mid=s+(e-s)/2;
        int ans=-1;
        while(e>=s){
            if(arr[mid]==target){
                ans=mid;
                e=mid-1;
            }
            if(arr[mid]>target){
                e=mid-1;
            }
            if(arr[mid]<target){
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }

    int LastOccurence(vector<int>& arr, int target){
        int s=0,e=arr.size()-1,mid=s+(e-s)/2;
        int ans=-1;
        while(e>=s){
            if(arr[mid]==target){
                ans=mid;
                s=mid+1;
            }
            if(arr[mid]>target){
                e=mid-1;
            }
            if(arr[mid]<target){
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    int totalOccurence(int first, int last){
        return last-first+1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answers;
        answers.push_back(firstOccurence(nums, target));
        answers.push_back(LastOccurence(nums, target));
        int total = totalOccurence(answers[0], answers[1]);
        return answers;
    }
};