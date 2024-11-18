# include <iostream>
using namespace std;

int MissingElement(int *arr, int size){
    int s=0,e=size-1,mid=s+(e-s)/2;
    int index=2147483647;
    while(e>=s){
        if(arr[mid]==mid+1){
            s=mid+1;
        }
        if(arr[mid]==mid+2){
            e=mid-1;
            index=min(index,mid);
        }
        
        mid=s+(e-s)/2;
    }
    return index;
}

int main(){
    int arr[] = {1,2,4,5,6,7,8,9};
    int index=MissingElement(arr, 8);
    if(index>=0)
    cout<<"Element found at index: "<<index;
    else
    cout<<"Element Not Found";
}