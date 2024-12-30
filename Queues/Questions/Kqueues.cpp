# include <iostream>
using namespace std;

class Kqueues
{
    public:
    int n,k,freespot;
    int *arr, *front, *rear, *next;

    Kqueues(int _n, int _k): n(_n), k(_k), freespot(0) {
        arr = new int [n];
        front = new int [k];
        rear = new int [k];
        next = new int[n];
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1; 
        for(int i=0;i<k;i++){
            front[i]=rear[i]=-1;
        }
    }

    bool push(int x, int qi){
        //Overflow check
        if(freespot==-1){
            cout<<"Queue Overflow";
            return false;
        }
        //Make index equal to the next freespot
        int index=freespot;

        //Update Freespot
        freespot=next[index];

        //Check if Queue is empty
        if(front[qi]==-1){
            front[qi]=index;
        }else{
            //Link new element to Qi's rearest element
            next[rear[qi]]=index;
        }
        //Update next
        next[index]=-1;

        //Update the reat index
        rear[qi]=index;

        //Insert into the array
        arr[index]=x;

        return true;
    }

    int pop(int qi){
        //Check Underflow
        if(freespot==-1){
            return -1;
        }
        //We will pop from the front
        int index=front[qi];
        //Update the new front index
        front[qi]=next[index];
        //manage freespot
        //This is because the next is initialized with next free spot in the start
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }

};