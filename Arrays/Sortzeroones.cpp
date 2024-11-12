# include <iostream>
using namespace std;

void sort(int arr[], int size){
    int zeros=0,ones=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0)
        zeros++;
        else
        ones++;
    }
    int c=0;
    while(zeros!=0){
        arr[c]=0;
        c++;
        zeros--;
    }
    while(ones!=0){
        arr[c]=1;
        c++;
        ones--;
    }
    cout<<"Printing array (";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<")";
}

int main(){
    int arr[] = {0,1,0,0,0,1,1,0,1,0,0,1};
    int size = 12;
    sort(arr, size);
}