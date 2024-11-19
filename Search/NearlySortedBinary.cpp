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
        else if(arr[mid-1]==ele && mid-1>=0){
            index=mid-1;
            break;
        }
        else if(arr[mid+1]==ele && mid+1<size){
            index=mid+1;
            break;
        }
        if(ele>arr[mid]){
            s=mid+2;
        }
        if(ele<arr[mid]){
            e=mid-2;
        }
        mid=s+(e-s)/2;
    }
    return index;
}

int main(){
    int arr[] = {20,10,30,50,40,70,60,90,80,100};
    int index=binarySearch(arr, 10, 100);
    if(index>=0)
    cout<<"Element found at index: "<<index;
    else
    cout<<"Element Not Found";
}