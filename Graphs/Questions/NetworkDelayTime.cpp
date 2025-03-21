# include <vector>
# include <unordered_map>
# include <queue>
using namespace std;

class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            unordered_map<int, vector<pair<int, int>>> adjList;
            for (auto &time : times) {
                int u = time[0], v = time[1], w = time[2];
                adjList[u].push_back({v, w});
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> dist(n + 1, INT_MAX);
            
            dist[k] = 0;
            pq.push({0, k});
            
            while (!pq.empty()) {
                auto [d, node] = pq.top();
                pq.pop();
                for (auto &[neighbor, weight] : adjList[node]) {
                    if (dist[node] + weight < dist[neighbor]) {
                        dist[neighbor] = dist[node] + weight;
                        pq.push({dist[neighbor], neighbor});
                    }
                }
            }
            int maxTime = 0;
            for (int i = 1; i <= n; i++) {
                if (dist[i] == INT_MAX) return -1;
                maxTime = max(maxTime, dist[i]);
            }
            
            return maxTime;
        }
    };