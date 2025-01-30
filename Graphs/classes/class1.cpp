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
};
template<typename T>
class GraphWeighted {
public:
    unordered_map<T, list<pair<T,int>>> adjList;

    void addEdge(T u, T v, int wt, bool direction) {
        // direction -> 0 -> undirected;
        // direction -> 1 -> directed;
        if (direction == true) {
            // u -> v
            adjList[u].push_back({v,wt});
        } else {
            // u <-> v
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        cout<<"Printing List"<<endl;
        printadjList();
        cout<<endl;
    }

    void printadjList() {
        for (auto i : adjList) {
            cout << i.first << "'s Adj list is : {";
            for (auto j : i.second) {
                cout <<"{ "<<j.first<<", "<<j.second<<" }" << " ";
            }
            cout << "}" << endl;
        }
    }

    void bfsTraversal(T src, unordered_map<T,bool> &visited){
        //adj list already data member me hai
        //visited map banao
        // This particular code will not work in case of disconnected graph
        //queue mei push karna hai
        queue<T> q;
        //visited set mei dalna hai
        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            T front = q.front();
            cout<<front<<" ";
            q.pop();

            // ab neighbours par janna hai
            for(auto nbd: adjList[front]){
                if(!visited[nbd.first]){
                    q.push(nbd.first);
                    visited[nbd.first]=true;
                }
            }
        }
        
    }

    void dfstraversal(T src, unordered_map<T,bool> &visited){
        // Recursion se karna hai
        // We already have adjacency list
        // Lessgo
        visited[src]=true;
        cout<<src<<" ";
        for(auto nbd: adjList[src]){
            if(!visited[nbd.first]){
                dfstraversal(nbd.first, visited);
            }
        }
    }
};

int main() {
    // Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(1, 3, 0);
    // g.addEdge(2, 3, 0);

    // cout << "Printing Adj List:" << endl;
    // g.printadjList();

    GraphWeighted<char> g;
    g.addEdge('a', 'b', 10, 0);
    g.addEdge('a ', 'c', 20, 0);
    g.addEdge('c', 'd', 17, 0);
    g.addEdge('c', 'e', 17, 0);
    g.addEdge('d', 'e', 17, 0);
    g.addEdge('d', 'f', 17, 0);

    cout << "Printing Adj List:" << endl;
    g.printadjList();

    cout << "\nBFS Traversal from 'a':" << endl;
    // g.bfsTraversal('a');

    GraphWeighted<char> gdiss;
    gdiss.addEdge('a', 'b', 5, 0);
    gdiss.addEdge('a', 'd', 5, 0);
    gdiss.addEdge('b', 'c', 15, 0);
    gdiss.addEdge('b', 'd', 15, 0);
    gdiss.addEdge('e', 'f', 15, 0);
    gdiss.addEdge('e', 'g', 5, 0);

    cout << "\nPrinting Adj List with disconnected components:" << endl;
    gdiss.printadjList();

    cout << "\nBFS Traversal from 'a':" << endl;
    unordered_map<char, bool> visited;
    cout << "DFS Traversal: ";
    for(char i='a'; i<='g'; i++){
        if(!visited[i]){
            g.dfstraversal(i, visited);
        }
    }

    return 0;
}
