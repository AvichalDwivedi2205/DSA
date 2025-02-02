# include<vector>
# include <unordered_map>
# include <iostream>
# include <queue>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool solveBFS(vector<vector<int>>& adj, int src, unordered_map<int, bool> &vis){
        queue<int> q;
        unordered_map<int, int> parent;
        // push the src node
        q.push(src);
        vis[src]=true;
        parent[src]=-1;

        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto nbd: adj[front]){
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
    
    bool solveDFS(vector<vector<int>>& adj, int src, unordered_map<int, bool> &vis, int parent){
        vis[src] = true;
        
        for(auto nbr : adj[src]){
            if(nbr==parent) continue;
            if(!vis[nbr]){
                bool ans = solveDFS(adj, nbr, vis, src);
                if(ans) return true;
            } else{
                return true;
            }
        }
        return false;
    }

    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int, bool> vis;
        for (int i=0;i<adj.size(); i++){
            if(!vis[i]){
                bool ans = solveDFS(adj, i, vis, -1);
                if(ans==true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends