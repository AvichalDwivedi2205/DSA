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
    int Solution2(vector<int>& arr){
        int s=0, e=arr.size()-1, mid=s+(e-s)/2;
        while(s<e){
            if(arr[mid]<arr[mid+1])
            s=mid+1;
            else
            e=mid;
            mid=s+(e-s)/2;
        }
        return s;
    }
};