# include<vector>
# include <unordered_map>
# include <queue>
# include <iostream>
using namespace std;

class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            unordered_map<int, list<int>> mp;
            vector<int> indegree(numCourses, 0);
            for(auto pre:prerequisites){
                mp[pre[1]].push_back(pre[0]);
                indegree[pre[0]]++;
            }
            queue<int> q;
            for(int i=0;i<numCourses;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            vector<int> ans;
            while(!q.empty()){
                int ele = q.front();
                q.pop();
                ans.push_back(ele);
                for(auto nbr:mp[ele]){
                    indegree[nbr]--;
                    if(indegree[nbr]==0)
                    q.push(nbr);
                }
            }
            return (ans.size()==numCourses) ? ans : vector<int>{};
        }
    };