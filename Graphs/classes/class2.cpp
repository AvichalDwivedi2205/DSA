#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction) {
        // direction -> 0 -> undirected;
        // direction -> 1 -> directed;
        if (direction == true) {
            // u -> v
            adjList[u].push_back(v);
        } else {
            // u <-> v
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        cout << "Edge added: " << u << " -> " << v << endl;
    }

    void printadjList() {
        for (auto i : adjList) {
            cout << i.first << "'s Adj list is : {";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << "}" << endl;
        }
    }

    bool GraphisCyclic(int src){
        queue<int> q;
        unordered_map<int, bool> vis;
        unordered_map<int, int> parent;
        // push the src node
        q.push(src);
        vis[src]=true;
        parent[src]=-1;

        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto nbd: adjList[front]){
                if(vis[nbd]==false){
                    q.push(nbd);
                    vis[nbd]=true;
                    parent[nbd]=front;
                }else{
                    if(parent[front]!=nbd){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(2, 5, 0);

    bool isCyclic = g.GraphisCyclic(0);
    if(isCyclic){
        cout<<"Graph has a cycle"<<endl;
    } else {
        cout<<"Graph does not have a cycle"<<endl;
    }
    for(int i=0; i<6; i++){
        if(g.GraphisCyclic(i)){
            cout<<"Graph has a cycle"<<endl;
            break;
        }
    }

    return 0;
}