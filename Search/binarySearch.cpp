# include <iostream>
using namespace std;

int binarySearch(int *arr, int size, int ele){
    int s=0,e=size-1,mid=s+(e-s)/2;
    int index=-1;
    for(int i=0;i<size;i++){
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
    int arr[] = {2,3,5,6,7,8,20,282,2828,389333};
    int index=binarySearch(arr, 10, 21);
    if(index>=0)
    cout<<"Element found at index: "<<index;
    else
    cout<<"Element Not Found";
}