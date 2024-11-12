# include <iostream>
using namespace std;

void Shift(int arr[], int size, int shift){
    int shiftNew = shift%size;
    int a[5];
    int c=0;
    for(int i=size-shiftNew; i<size; i++){
        a[c] = arr[i];
        c++;
    }
    for(int i=0;i<size-shift;i++){
        a[c]=a[i];
        c++;
    }
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int arr[] = {2,10,11,13,7};
    int size = 5;
    Shift(arr, size, 8);

}