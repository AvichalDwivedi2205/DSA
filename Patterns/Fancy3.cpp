// ********1********
// *******2*2*******
// ******3*3*3******
// *****4*4*4*4*****
// ****5*5*5*5*5****

#include<iostream>

using namespace std;
// Method 1
int main(){
    int n=5;
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=0;j<17;j++){
            if(j>8-i-1&&j<8+i+1){
                if(c%2==0)
                cout<<i+1;
                else
                cout<<"*";
                c++;
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}