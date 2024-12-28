# include <iostream>

using namespace std;

class NStack
{
    int *a, *top, *next;
    int n;// number of stacks
    int size;//size of ,min array
    int freespot;//teels free space in the main array
public:
    NStack(int _n, int _s) : n(_n), size(_s){
        freespot=0;
        a=new int[size];
        top=new int[n];
        next=new int[size];

        for(int i=0;i<n;i++){
            top[i]=-1;
        }
        for(int i=0;i<size-1;i++){
            next[i]=i+1;
        }
        next[size-1]=-1;
    }
    bool push(int X, int m){
        if(freespot==-1){
            return false; //stack overflow
        }
        //Find Index
        int index=freespot;
        //update next for the location before top
        freespot=next[index];
        //insert in array
        a[index]=X;
        //update next for the location before top
        next[index]=top[m-1];
        //update location of top
        top[m-1]=index;
        return true;
    }
    int pop(int m){
        if(top[m-1]==-1){
            return -1;
        }
        //index of top element
        int index=top[m-1];
        //update the top to the index just before top
        top[m-1]=next[index];
        //Whuich element was deleted?
        int popElement=a[index];
        //updating next to the available freespot
        next[index]=freespot;
        //updating the freespot the in index just deleted
        freespot=index;
        return popElement;
    } 

    ~NStack(){
        delete[] a;
        delete[] top;
        delete[] next;
    }
};

int main(){
    NStack s(3,6);
    cout<<s.push(10,1)<<endl;
    cout<<s.pop(1)<<endl;
}