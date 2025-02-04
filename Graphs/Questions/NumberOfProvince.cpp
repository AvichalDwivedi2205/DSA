# include <iostream>
# include <unordered_map>
using namespace std;

class Solution {
public:

    void dfs(unordered_map<int, bool> &vis, int src, vector<vector<int>>& isConnected){
        vis[src]=true;
        for(int i=0;i<isConnected[src-1].size();i++){
            if(isConnected[src-1][i]==1 && !vis[i+1]){
                dfs(vis,i+1,isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // The following is an adjacency matrix representing a graph
        // We will have to apply dfs and i++ if not visited simple
        int province = 0;
        unordered_map<int,bool> vis;
        for(int i=1;i<=isConnected.size();i++){
            if(!vis[i]){
                dfs(vis, i, isConnected);
                province++;
            }
        }
        return province;
    }
};