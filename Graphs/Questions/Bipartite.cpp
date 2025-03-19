# include <vector>
# include <queue>
using namespace std;

class Solution {
    public:
    
        void dfs(vector<vector<int>>& graph, vector<int>& divide, bool& bi, int src, int number){
            divide[src]=number;
            for(auto nbr:graph[src]){
                if(divide[nbr]==-1){
                    dfs(graph,divide,bi,nbr,!number);
                }else if(divide[nbr]==divide[src]){
                    bi=false;
                    return;
                }
            }
        }
    
        bool isBipartite(vector<vector<int>>& graph) {
            // 0 and 1 partitioning 
            // we have been given an adjList in the form of a 2d vector
            vector<int> divide(graph.size(),-1);
            bool bi=true;
            int row=graph.size();
            for(int i=0;i<row;i++){
                if(divide[i]==-1){
                    dfs(graph,divide,bi,i,0);
                }
            }
            return bi;
        }
    };