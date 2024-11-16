# include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void missing(int *arr, int size){
    for(int i=0;i<size;i++){
        int index = abs(arr[i]);
        if(arr[index-1]>0)
        arr[index-1]*=-1; 
    }
    for(int i=0;i<size;i++){
        if(arr[i]>0)
        cout<<i+1<<" ";
    }
}

void sortingMethod(int *a, int n){
    int i=0;
    while(i<n){
        int index = a[i]-1;
        if(a[index!=a[i]]){
            swap(a[i], a[index]);
        }
        else{
            ++i;
        }
    }
    for(int i=0; i<n;i++){
        if(a[i]!=i+1)
        cout<<i+1<<" ";
    }
}

int main(){
    int arr[] = {3,4,5,6,7,2,5,6,12,5,6,7,11};
    int size = 13;
    missing(arr, size);
}