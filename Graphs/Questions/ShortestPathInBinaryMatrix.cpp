# include <vector>
# include <queue>
# include <iostream>
# include <tuple>
using namespace std;

class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
    
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    
            vector<vector<int>> dist(n, vector<int>(n, 1e9));
            vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, 
                                              {0, -1},          {0, 1}, 
                                              {1, -1}, {1, 0}, {1, 1}};
            
            pq.push({1, 0, 0});
            dist[0][0] = 1;
    
            while (!pq.empty()) {
                auto [d, r, c] = pq.top();
                pq.pop();
    
                if (r == n - 1 && c == n - 1) return d;
    
                for (const vector<int>& dir : directions) {
                    int dr = dir[0], dc = dir[1];
                    int nr = r + dr;
                    int nc = c + dc;
    
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0) {
                        if (d + 1 < dist[nr][nc]) {
                            dist[nr][nc] = d + 1;
                            pq.push({d + 1, nr, nc});
                        }
                    }
                }
            }
            return -1;
        }
    };
    
    class SolutionQueue {
        public:
            int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
                int n = grid.size();
                if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        
                // priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
                queue<tuple<int,int,int>> pq;
                vector<vector<int>> dist(n, vector<int>(n, 1e9));
                vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, 
                                                  {0, -1},          {0, 1}, 
                                                  {1, -1}, {1, 0}, {1, 1}};
                
                pq.push({1, 0, 0});
                dist[0][0] = 1;
        
                while (!pq.empty()) {
                    auto [d, r, c] = pq.front();
                    pq.pop();
        
                    if (r == n - 1 && c == n - 1) return d;
        
                    for (const vector<int>& dir : directions) {
                        int dr = dir[0], dc = dir[1];
                        int nr = r + dr;
                        int nc = c + dc;
        
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0) {
                            if (d + 1 < dist[nr][nc]) {
                                dist[nr][nc] = d + 1;
                                pq.push({d + 1, nr, nc});
                            }
                        }
                    }
                }
                return -1;
            }
        };
        