// Use 2 arrays and store first half in one and dthe second hald in the other 
// Easy as fuck

# include <iostream>
# include <queue>
# include <stack>
using namespace std;

void Interleave(queue<int> &first){
    //Push First Half of the first queue in the second queue
    queue<int> second;
    int size=first.size();
    for(int i=0; i<size/2; i++){
        int temp=first.front();
        first.pop();
        second.push(temp);
    }

    //Merge both the halves
    for(int i=0;i<size/2;i++){
        int temp = second.front();
        second.pop();
        first.push(temp);
        temp =first.front();
        first.pop();
        first.push(temp);
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
    cout<<"Even Case"<<endl;;

    Interleave(q);

    while(!q.empty()){
        int ele=q.front();
        q.pop();
        cout<<ele<<" ";
    }
    cout<<endl;
    queue <int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.push(50);
    cout<<"Odd Case"<<endl;;

    Interleave(qu);

    while(!qu.empty()){
        int ele=qu.front();
        qu.pop();
        cout<<ele<<" ";
    }
}