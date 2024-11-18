#include <vector>
using namespace std;

class Solution {
public:

    int pivotElement(vector<int>& arr){
        int s=0,e=arr.size()-1,mid=s+(e-s)/2;
        int index=-1;
        while(e>=s){
            if(s==e){
               index=s;
               break;
            }
            if (mid > 0 && arr[mid] < arr[mid - 1]) {
                index = mid - 1;
                break;
            }
            if (mid < arr.size() - 1 && arr[mid + 1] < arr[mid]) {
                index = mid;
                break;
            }
            if(arr[s]>arr[mid])
            e=mid;
            else
            s=mid+1;
            mid=s+(e-s)/2;
        }
        return index;
    }

    int search(vector<int>& nums, int target) {
        int pivot = pivotElement(nums);
        int s=0,e=0,mid=0;
        if(pivot<0){
            s=0;
            e=nums.size()-1;
            mid=s+(e-s)/2;
        }
        else if(pivot>=0 && target<nums[0]){
            s=pivot+1; 
            e=nums.size()-1;
            mid=s+(e-s)/2;
        }else if(pivot>=0 && target>=nums[0]){
            s=0;
            e=pivot;
            mid=s+(e-s)/2;
        }
        int index=-1;
        while(e>=s){
            if(nums[mid]==target){
                index=mid;
                break;
            }
            if(target>nums[mid]){
                s=mid+1;
            }
            if(target<nums[mid]){
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return index;
        }
};