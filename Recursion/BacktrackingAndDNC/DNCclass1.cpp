# include <iostream>
using namespace std;

void merge(int arr[], int s, int e){
    int mid=s+e/2;
    // left array=mis-s+1 
    //right array e-mid
     int lenL = mid-s+1;
     int lenR = e-mid;

     //Create Left And Right Array
     int *left = new int[lenL];
     int *right = new int[lenR];

     //copy values from original array to left array
     int k=s;
     //k->srarting index of left array values in original arrays
     for(int i=0;i<lenL; i++){
        left[i]=arr[k];
        k++;
     }
     //copy values from original array to right array
     k=mid+1;
     //k->srarting index of right array values in original arrays
     for(int i=0;i<lenR;i++){
        left[i]=arr[k];
        k++;
     }
     //Actual merge ka logic
     //left and right array is already sorted
     int indexL=0;
     int indexR=0;
     //yahi pr galti krte hai log
     int mainArrayIndex=s;
     while(indexL<lenL && indexR<lenR){
        if(left[indexL]<right[indexR]){
            arr[mainArrayIndex]=left[indexL];
            mainArrayIndex++;
            indexL++; 
        }else{
            arr[mainArrayIndex]=right[indexR];
            mainArrayIndex++;
            indexR++; 
        }
     }

     //2more cases
     //right array still has elements but the left array is over
     while(indexR<lenR){
        arr[mainArrayIndex]=right[indexR];
        indexR++;
        mainArrayIndex++;
     }
     //left array still has elements and the right array is over
     while(indexL<lenL){
        arr[mainArrayIndex]=left[indexL];
        indexL++;
        mainArrayIndex++;
     }
     delete[] left;
     delete[] right;
}

void mergeSort(int arr[], int s, int e){
    if(s>=e)
    return;
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);

    //s->mid tak
    //mid+1->end tak

    //recursion bhaiya ko bulao and sort karwao
    //recursive call for left array
    mergeSort(arr,s,mid);
    //recursive call for right array
    mergeSort(arr,mid+1,e);
    //Merge 2 sorted arrays
    merge(arr,s,e);
}

int main(){
    int arr[] = {2,1,6,9,4,5};
    int size=6;
    mergeSort(arr, 0, size-1);
    return 0;
}