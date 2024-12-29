# include <iostream>
# include <queue>
# include <stack>
using namespace std;

void reverseKQueue(queue<int> &q, int k){
    stack <int> s;
    int a=q.size()-k;
    while(k--){
        int front=q.front();
        q.pop();
        s.push(front);
    }

    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    while(a--){
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

int main(){
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    reverseKQueue(q, 4);
    while(!q.empty()){
        int ele=q.front();
        q.pop();
        cout<<ele<<" ";
    }
}