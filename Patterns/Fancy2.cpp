// A
// ABA
// ABCBA
// ABCDBCA

#include <iostream>

using namespace std;

int main(){
    int n=5;
    for(int i=0;i<n;i++){
        char ch='A';
        for(int j=0;j<(2*i)+1;j++){
            cout<<ch;
            if(j<i)
            ch=ch+1;
            else
            ch=ch-1;
        }
        cout<<endl;
    }
}
