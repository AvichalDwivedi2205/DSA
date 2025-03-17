#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Graph{
    public: 
       unordered_map<int, list<pair<int,int>>> adjList;
       void addEdge(int u, int v, int wt, bool direction){
        if(direction==1){
            //Directed Graph
            adjList[u].push_back(make_pair(v,wt));
        }else{
            //Undirected Graph
            adjList[u].push_back(make_pair(v,wt));
            adjList[v].push_back(make_pair(u,wt));
        }
       }

       void printAdjList(){
           for(auto i:adjList){
               cout<<i.first<<"-> {";
               for(auto j:i.second){
                   cout<<"("<<j.first<<","<<j.second<<")";
               }
               cout<<"}"<<endl;
           }
       }

       void topoOrderDfs(int src, stack<int> &topoOrder, unordered_map<int,bool> &visited){
            visited[src] = true;
            for(auto nbr: adjList[src]){
                int nbrNode=nbr.first;
                int wt = nbr.second;
                if(!visited[nbrNode]){
                    topoOrderDfs(nbrNode, topoOrder, visited);
                }
            }
            topoOrder.push(src);
       }

       void shortestPathDFS(int dest, stack<int> &topo, int n){
          vector<int> dist(n, 7678167);
          // initially mainitain src
          int src=topo.top();
          topo.pop();
          dist[src]=0;

          //update neighbour distance for source node
          for(auto nbr: adjList[src]){
            int nbrNode=nbr.first;
            int wt = nbr.second;
            if(dist[src]+wt<dist[nbrNode]){
                dist[nbrNode]=dist[src]+wt;
            }
          }

          //apply the same above concept for all the remaining nodes
          while(!topo.empty()){
            int src=topo.top();
            topo.pop();

            //update neighbour distance for source node
            for(auto nbr: adjList[src]){
                int nbrNode=nbr.first;
                int wt = nbr.second;
                if(dist[src]+wt<dist[nbrNode]){
                    dist[nbrNode]=dist[src]+wt;
                }
            }
          }
          cout<<"Printing the distance array"<<endl;
          cout<<1<<endl;
          for(auto i:dist){
              cout<<i<<" ";
          }
       }
};

int main(){
    Graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,3,1,1);
    g.printAdjList();

    stack<int> topOrder;
    int src=0;
    unordered_map<int,bool> visited;
    g.topoOrderDfs(src, topOrder, visited);
    cout<<"Printing the distance array";
    g.shortestPathDFS(3,topOrder,5);

    return 0;
}