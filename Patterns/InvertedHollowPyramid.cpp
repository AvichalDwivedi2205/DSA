#include<iostream>

using namespace std;
int main(){
    int n = 5;
    // Method 1
    for(int i=0; i<n; i++){
        for(int j=0;j<(2*n)-1;j++){
            if(j==i || j==(2*n)-2-i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}