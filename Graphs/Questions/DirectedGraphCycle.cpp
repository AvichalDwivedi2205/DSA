# include<vector>
# include <unordered_map>
# include <iostream>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool checkCyclic(int src,  unordered_map<int, bool> &vis, unordered_map<int,
    bool> &dfsTrack, vector<vector<int>> &adj){
        
        vis[src]=true;
        dfsTrack[src]=true;
        
        for(auto nbr:adj[src]){
            if(!vis[nbr]){
                bool ans = checkCyclic(nbr, vis, dfsTrack, adj);
                if(ans==true) return true;
            }else if (vis[nbr] && dfsTrack[nbr]){
                return true;
            }
        }
        
        // Backtracking
        // Make it false - Yahi galti karta hoon
        dfsTrack[src]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        unordered_map<int, bool> vis;
        unordered_map<int, bool> dfsTrack;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool ans = checkCyclic(i, vis, dfsTrack, adj);
                if(ans==true) return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends