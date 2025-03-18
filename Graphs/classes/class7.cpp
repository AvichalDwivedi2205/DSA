// Bellmann Ford Algorithm
// Relaxation - (n-1) times peform
// n is number of nodes
// n-1 times shortest distance will be there
// If any updation happens after n-1 times then it means that a negative cycle is present

#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
# include <set>

using namespace std;

class Graph{
    public: 
       unordered_map<int, list<pair<int,int>>> adjList;

       void addEdge(int u, int v, int wt, bool direction){
            if(direction==0){
                adjList[u].push_back({v,wt});
                adjList[v].push_back({u,wt});
            }else{
                adjList[u].push_back({v,wt});
            }
       }

       void printAdjList(){
        for(auto i: adjList){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"{"<<j.first<<","<<j.second<<"}, ";
            }
        }
       }
       void bellmanFord(int n, int src){
        vector<int> dist(n,9389389);
        dist[src-'A']=0;
        // Relaxation N-1 Times
        for(int i=1;i<n;i++){
            // traverse on matrix edge list
            for(auto a:adjList){
                for(auto b:a.second){
                    char u=a.first;
                    char v=b.first;
                    int wt=b.second;
                    if(dist[u-'A']+wt<dist[v-'A']){
                        dist[v-'A']=dist[u-'A']+wt;
                    }
                }
            }
        }
        bool flag=false;
        for(auto a:adjList){
            for(auto b:a.second){
                char u=a.first;
                char v=b.first;
                int wt=b.second;
                if(dist[u-'A']+wt<dist[v-'A']){
                    flag=true;
                    break;
                }
            }
        }
        if(flag) cout<<"Negative Cycle"<<endl;
        else{
            cout<<"No Negative Cycle"<<endl;
            for(auto i:dist){
                cout<<i<<" ";
            }
        } 
    }

    void floydWarshal(int n){
        // Exploring all of the possible paths
        // dist[src][dest] -> min(dist(src->0->dest), dist(src->1->dest), dist(src->2->dest),....)
        vector<vector<int>> dist(n, vector<int> (n,1e9));
        //diagonal 0
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        // some weights are given in the graph so update distance accroadingly
        for(auto a:adjList){
            for(auto b:a.second){
                int u=a.first;
                int v=b.first;
                int wt=b.second;
                dist[u][v]=wt;
            }
        }
        //main loop
        for(int helper=0;helper<n;helper++){
            for(int src=0;src<n;src++){
                for(int dest=0;dest<n;dest++){
                    dist[src][dest]=min(dist[src][dest], dist[src][helper]+dist[helper][dest]);
                }
            }
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    // KosaRaju Algorithm
    // Strongly connected components
    // Edge Reverse karenge and then apply dfs on count
    
};

int main(){
    Graph g;
    // g.addEdge('A','B',-1,1);
    // g.addEdge('B','E',2,1);
    // g.addEdge('E','D',-3,1);
    // g.addEdge('D','C',5,1);
    // g.addEdge('A','C',4,1);
    // g.addEdge('B','C',3,1);
    // g.addEdge('B','D',2,1);
    // g.addEdge('D','B',1,1);
    g.addEdge(0,1,3,1);
    g.addEdge(1,0,2,1);
    g.addEdge(0,3,5,1);
    g.addEdge(1,3,4,1);
    g.addEdge(3,2,2,1);
    g.addEdge(2,1,1,1);
    g.printAdjList();
    g.floydWarshal(4);  
    // g.bellmanFord(5,'A');
    return 0;
}