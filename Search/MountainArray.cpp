// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]

// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]

// Output: 1

 

// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.


#include <vector>
using namespace std;

class Solution {
public:
//My Solution
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0,e=arr.size()-1,mid=s+(e-s)/2;
        int index=-1;
        while(e>=s){
            if(mid>0 && mid<arr.size()-1){
                if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                index=mid;
                break;
                }
                else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }else if (mid==0)
            s=mid+1;
            else if(mid==arr.size()-1)
            e=mid-1;
            
            mid=s+(e-s)/2;
        }
        return index;
    }
    // Babbar Solution
     int Solution2(vector<int>& arr) {
        int s = 0, e = arr.size() - 1;
        int mid = s + (e - s) / 2;

        // Binary search loop
        while (s < e) {
            // If mid element is less than the next element,
            // we are in the increasing part of the mountain
            if (arr[mid] < arr[mid + 1])
                s = mid + 1;  // Move right since peak lies on the right
            else
                e = mid;      // We're in the decreasing part or at the peak, so move left

            // Recalculate mid
            mid = s + (e - s) / 2;
        }

        // At the end, s == e, which is the peak index
        return s;
    }
};