# include <iostream>
using namespace std;

int Transpose(int arr[][3], int size){
    for (int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            swap(arr[i][j], arr[j][i]); 
        }
    }
}

int main(){
    int arr[3][3] = {
        {2,4,6},
        {8,3,5},
        {7,9,1}
    };
    int size = 3;
    Transpose(arr, size);
}