// Use 2 arrays and store first half in one and dthe second hald in the other 
// Easy as fuck

# include <iostream>
# include <queue>
# include <deque>
# include <stack>
using namespace std;

void PrintFirstNegative(int *arr, int n,int k){
    deque <int> dq;

    //Process the first k elements
    for(int i=0;i<k;i++){
        if(arr[i]<0)
        dq.push_back(i);
    }

    // Process the remaining windows
    for(int index=k; index<n; index++){
        //aage nikalne se pehle purani window ka answer nuikaldo
        if(dq.empty())
        cout<<"0"<<" ";
        else
        cout<<arr[dq.front()]<<" ";
        //Removal - jo bhi index out of range ho then usko remove kardo
        if(index - dq.front()>=k){
            dq.pop_front();
        }
        //Addition
        if(arr[index]<0){
            dq.push_back(index);
        }
    } 

    //Last Window alag se process karna hoga
    if(dq.empty())
    cout<<"0"<<" ";
    else
    cout<<arr[dq.front()]<<" ";
}

int main(){
    int arr[] = {2,-5,4,-1,-2,0,5};
    int size=7;
    int k=3;
    PrintFirstNegative(arr, size, k);
}