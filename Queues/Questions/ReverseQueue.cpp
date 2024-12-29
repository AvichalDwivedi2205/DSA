# include <iostream>
# include <queue>
# include <stack>
using namespace std;

void reverseQueue(queue<int> &q){
    stack <int> s;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        s.push(front);
    }

    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
}

void reverseQueueRec(queue<int> &q){
    //We will just have to put the 10 in the last and then recursion will tke care of the rest
    if(q.empty())
    return;
    int ele=q.front();
    q.pop();
    reverseQueueRec(q);
    q.push(ele);
}

int main(){
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    reverseQueueRec(q);
    while(!q.empty()){
        int ele=q.front();
        q.pop();
        cout<<ele<<" ";
    }
}