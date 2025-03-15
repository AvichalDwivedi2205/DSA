# include <iostream>
# include <unordered_map>
# include <list>
# include <stack>
# include <queue>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int>> adjList;

        void addEdge(int u, int v, bool direction){
            // direction -> 0 -> undirected;
            // direction -> 1 -> directed;
            if(direction==1){
                // onlu one push will happen
                // u -> v
                adjList[u].push_back(v);
            }else {
                // Both the pushing will happen
                // u <-> v
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto i:adjList){
                cout<<i.first<<"-> {";
                for(auto j:i.second){
                    cout<<j<<",";
                }
                cout<<"}"<<endl;
            }
        }

        void topSortDFS(int src, unordered_map<int, bool> &vis, stack<int> &s){
            vis[src]=true;
            for(auto nbr:adjList[src]){
                if(!vis[nbr]){
                    topSortDFS(nbr, vis, s);
                }
            }
            s.push(src);
        }

        void topSortBFS(int n){
            queue<int> q;
            unordered_map<int, int> indegree;

            // initialize the indegree array
            for(auto i:adjList){
                for( auto nbr:i.second){
                    indegree[nbr]++;
                }
            }
            //Push all the zero indegree vali node in the queue
            for(int node=0; node<n;node++){
                if(indegree[node]==0){
                    q.push(node);
                }
            }
            while(!q.empty()){
                int front=q.front();
                q.pop();
                cout<<front<<",";
                for(auto nbr:adjList[front]){
                    indegree[nbr]--;

                    //check for zero
                    if(indegree[nbr]==0){
                        q.push(nbr);
                    }
                }
            }
            // If topological sort size is equal to n then there will be no loops.
            // This is also known as Kahn's Algorithm
            // Directed graph cycle
            // This code will only be applicable if there is no cycle
            // This could also be used to find cycle
            // if ans.size()==adj.size() then no cycle else cycle will be present
            // This will not work in a cyclic graph because there will be a case where a part of graph will be left unvisited
            // This is because the indegree of that node will never be zero
        }

        void shortestPath(int src, int dest){
            queue<int> q;
            unordered_map<int, bool> visited;
            unordered_map<int, int> parent;
            
            //initial state
            q.push(src);
            visited[src]=true;
            parent[src]=-1;

            while(!q.empty()){
                int front = q.front();
                for(auto nbr:adjList[front]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr]=true;
                        parent[nbr]=front;
                    }
                }
            }
            // parent array is ready
            vector<int> ans;
            while(dest != -1){
                ans.push_back(dest);
                dest=parent[dest];
            }
            reverse(ans.begin(), ans.end());
            for(auto i:ans){
                cout<<i<<"->";
            }   
        }
};

int main(){ 
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(2,4,0);
    g.addEdge(3,5,0);
    g.addEdge(4,5,0);
    g.addEdge(5,6,0);
    g.addEdge(5,7,0);
    g.printAdjList();
    unordered_map<int, bool> vis;
    stack<int> st;
    for(int i=0;i<8;i++){
        if(!vis[i]){
            g.topSortDFS(i,vis,st);
        }
    }
    cout<<endl<<"Topological sort is ->"<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl<<"Topological sort is ->"<<endl; 
    g.topSortBFS(8);
    return 0;

    cout<<endl<<"Shortest Path is ->"<<endl;
    g.shortestPath(0,6);
}