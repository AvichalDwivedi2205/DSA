// 1
// 2*3
// 4*5*6
// 7*8*9*10
// 11*12*13*14*15
// 11*12*13*14*15
// 7*8*9*10
// 4*5*6
// 2*3
// 1

#include<iostream>

using namespace std;
// Method 1
int main(){
    int n=5;
    int start=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=(2*i);j++){
            if(j%2==0){
                start++;
                cout<<start;
            }else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    int start2=start-n+1;
    start=start2;
    for(int i=0;i<n;i++){
        for(int j=0;j<(2*n)-(2*i)-1;j++){
            if(j%2==0){
                cout<<start;
                start++;
            }else{
                cout<<"*";
            }
        }
        start2=start2-n+i+1;
        start=start2;
        cout<<endl;
    }
}