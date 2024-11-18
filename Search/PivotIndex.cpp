# include <iostream>
using namespace std;

int PivotIndex(int *arr, int size){
    int s=0,e=size-1,mid=s+(e-s)/2;
    int index=-1;
    while(e>=s){
        if(s==e)
        index=s;
        if(arr[mid]<arr[mid-1]){
            index=mid-1;
            break;
        }
        if(arr[mid+1]<arr[mid]){
            index=mid;
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

int main(){
    int arr[] = {12,14,16,18,20,2,3,6,8,9};
    int index=PivotIndex(arr, 10);
    if(index>=0)
    cout<<"Pivot Index is: "<<index;
    else
    cout<<"not Pivot Index";
}