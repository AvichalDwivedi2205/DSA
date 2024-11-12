# include <iostream>
using namespace std;

void Pair(int arr[], int size){
    cout<<"Printing Pairs";
    for(int i=0;i<size;i++){
        int temp = arr[i];
        for(int j=0;j<size;j++){
            cout<<"("<<temp<<", "<<arr[j]<<")";
        }
    }
}

int main(){
    int arr[] = {2,10,11};
    int size = 3;
    Pair(arr, size);
}