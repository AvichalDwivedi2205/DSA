//{ Driver Code Starts
// Initial Template for C++

# include <iostream>
# include <vector>
# include <queue>
# include <stack>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
  
    void topoSort(int node, vector<bool>& visited, stack<int>& st, vector<vector<pair<int, int>>>& adj) {
    visited[node] = true;
    for (auto it : adj[node]) {
        int neighbor = it.first;
        if (!visited[neighbor]) {
            topoSort(neighbor, visited, st, adj);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topoSort(i, visited, st, adj);
        }
    }

    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX) { 
            for (auto& neighbor : adj[node]) {
                int v = neighbor.first;
                int wt = neighbor.second;
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
    }

    // Step 5: Replace unreachable nodes with -1
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) dist[i] = -1;
    }

    return dist;
}
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends