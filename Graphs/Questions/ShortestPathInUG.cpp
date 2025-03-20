//{ Driver Code Starts
// Initial Template for C++

# include <iostream>
# include <vector>
# include <queue>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
   vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        queue<int> q;
        vector<int> dist(adj.size(), INT_MAX);
        dist[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int nbr : adj[node]) {
                if (dist[nbr] > dist[node] + 1) {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }
        for (int i = 0; i < adj.size(); i++) {
            if (dist[i] == INT_MAX) 
                dist[i] = -1;
        }
        
        return dist;
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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends