#include<vector>
# include <unordered_map>
# include <queue>
using namespace std;

bool solve(vector<vector<int>>& adj, int src, unordered_map<int, bool> &vis){
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
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int, bool> vis;
        for (int i=0;i<adj.size(); i++){
            if(!vis[i]){
                bool ans = solve(adj, i, vis);
                if(ans==true) return true;
            }
        }
        return false;
    }