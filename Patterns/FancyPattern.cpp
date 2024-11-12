// 1
// 2*2
// 3*3*3
// 4*4*4*4*

#include<iostream>

using namespace std;
// Method 1
int main(){
    int n=5;
    for(int i=0;i<n;i++){
        for(int j=0;j<(2*i)+1;j++){
            if(j%2==1)
            cout<<"*";
            else
            cout<<i+1;
        }
        cout<<endl;
}
}