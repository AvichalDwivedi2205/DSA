#include <iostream>
#include <unordered_map>
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
    unordered_map<T, list<pair<T,T>>> adjList;

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
};

int main() {
    // Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(1, 3, 0);
    // g.addEdge(2, 3, 0);

    // cout << "Printing Adj List:" << endl;
    // g.printadjList();

    GraphWeighted<int> g;
    g.addEdge(0, 1, 10, 1);
    g.addEdge(1, 2, 20, 1);
    g.addEdge(1, 3, 21, 1);
    g.addEdge(2, 3, 17, 1);

    cout << "Printing Adj List:" << endl;
    g.printadjList();

    return 0;
}
