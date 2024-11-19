// In the left of answer the first element is coming on the odd space and second on the even space.
// In the right of the answer the first element is coming on the even space and first on the odd space.
//In case of single element the start and the end are the same so that is the answer

# include <iostream>
using namespace std;

int binarySearch(int *arr, int size){
    int s=0,e=size-1,mid=s+(e-s)/2;
    while(e>=s){
        if(s==e)
        return s;

        if(mid&1){//If this gives true then odd number
          if(mid-1>=0 && arr[mid-1]==arr[mid])
          s=mid+1;
          else
          e=mid-1;
        }else{
            if(arr[mid]==arr[mid+1] && mid+1<size)
            s=mid+2;
            else
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int main(){
    int arr[] = {10,10,2,5,5,2,2,5,5,20,20,11,11};
    int index=binarySearch(arr, 13);
    if(index>=0)
    cout<<"Element found at index: "<<index;
    else
    cout<<"Element Not Found";
}