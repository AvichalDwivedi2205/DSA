# include<vector>
# include <unordered_map>
# include <queue>
# include <iostream>
using namespace std;

class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            if (prerequisites.empty()) return true;
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
            int numCompleted = 0;
            while (!q.empty()) {
                int ele = q.front();
                q.pop();
                numCompleted++;
    
                for (int neighbor : adjList[ele]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
            return numCompleted == numCourses;
        }
    };
    