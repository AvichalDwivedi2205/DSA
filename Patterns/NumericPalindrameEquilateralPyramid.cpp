#include <iostream>

using namespace std;

int main(){
    int n=5;
    for(int i=0;i<n;i++){
        int ch=1;
        for(int j=0;j<(2*n)+1;j++){
            if(j>=n-i-1 && j<=n-1){
                cout<<ch;
                ch=ch+1;
            }else if(j==n && i!=0){
                ch=ch-2;
                cout<<ch;
            }
            else if(j>n-1 && j<=n+i-1){
            ch=ch-1;
            cout<<ch;
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
