# include<vector>
# include <unordered_map>
# include <queue>
# include <iostream>
using namespace std;

class Solution {
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            // Anything having outdegree 0 is teminal node
            // We will reverse all the edges and then will follow indegree zero
            // Topological sort
            // This will give the answer
            unordered_map<int,list<int>> reverseGraph;
            vector<int> indegree(graph.size(),0);
            int n=graph.size();
            for(int i=0;i<n;i++){
                for(auto nbr:graph[i]){
                    reverseGraph[nbr].push_back(i);
                    indegree[i]++;
                }
            }
            // Now we have a reverse graph ready with indegree as well
            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
            vector<int> ans;
            while(!q.empty()){
                int ele=q.front();
                q.pop();
                ans.push_back(ele);
                for(auto nbr:reverseGraph[ele]){
                    indegree[nbr]--;
                    if(indegree[nbr]==0){
                        q.push(nbr);
                    }
                }
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
    };