# include <iostream>
using namespace std;

int unique(int arr[], int size){
    int uniqueElement = 0;
    for(int i=0;i<size;i++){
        uniqueElement = uniqueElement^arr[i];
    }
    return uniqueElement;
}

int main(){
    int arr[] = {2,10,11,10,12,13,15,14,15,14,13,2,12};
    int size = 13;
    int uniqueElement = unique(arr, size);
    cout<<uniqueElement;
}