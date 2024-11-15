#include <iostream>
using namespace std;

void NegativeLeft(int a[], int size){
    int j=0;
    for(int i=0; i<size; i++){
        if(a[i]<0){
            swap(a[i],a[j]);
            j++;
        }
    }
    cout<<"Array after stuff"<<endl;
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int arr[] = {-7,8,-2,6,-8,-9,7};
    int size = 7;
    NegativeLeft(arr, size);
}