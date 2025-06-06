# include<vector>
# include <unordered_map>
# include <queue>
# include <iostream>
using namespace std;

class Solution {
    public:
    
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int> indegree(numCourses, 0);
            unordered_map<int, list<int>> adjList;
            for (auto& it : prerequisites) {
                int course = it[0], prereq = it[1];
                indegree[course]++;
                adjList[prereq].push_back(course);
            }
            queue<int> q;
            for (int i = 0; i < numCourses; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
            vector<int> ans;
            while (!q.empty()) {
                int ele = q.front();
                q.pop();
                ans.push_back(ele);
    
                for (int neighbor : adjList[ele]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
            return (ans.size()==numCourses)?ans:vector<int>{};
        }
    };
    