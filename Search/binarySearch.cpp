# include <iostream>
using namespace std;

int binarySearch(int *arr, int size, int ele){
    int s=0,e=size-1,mid=s+(e-s)/2;
    int index=-1;
    while(e>=s){
        if(arr[mid]==ele){
            index=mid;
            break;
        }
        if(ele>arr[mid]){
            s=mid+1;
        }
        if(ele<arr[mid]){
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return index;
}

int main(){
    int arr[] = {2};
    int index=binarySearch(arr, 1, 0);
    if(index>=0)
    cout<<"Element found at index: "<<index;
    else
    cout<<"Element Not Found";
}