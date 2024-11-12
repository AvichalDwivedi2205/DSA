# include <iostream>
using namespace std;

int main(){
    int shift=2, num=10;
    //Here we will left shift 1 by shift times and then do bitwise operation with number to return the answer
    int mask = 1 << shift;
    int answer = num | mask;
    cout<<answer;
}