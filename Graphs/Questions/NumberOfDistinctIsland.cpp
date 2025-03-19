# include <iostream>
# include <queue>
# include <set>
using namespace std;

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> st;
        int row = grid.size();
        int col = grid[0].size();
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};
        queue<pair<int, int>> q;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 2;
                    q.push({i, j});
                    vector<pair<int, int>> island;
                    island.push_back({0, 0}); // start with (0,0) for relative position

                    while (!q.empty()) {
                        auto ele = q.front();
                        q.pop();
                        int cr = ele.first;
                        int cc = ele.second;
                        
                        for (int k = 0; k < 4; k++) {
                            int nr = cr + drow[k];
                            int nc = cc + dcol[k];
                            
                            if (nr >= 0 && nc >= 0 && nr < row && nc < col && grid[nr][nc] == 1) {
                                grid[nr][nc] = 2;
                                q.push({nr, nc});
                                island.push_back({nr - i, nc - j}); // Store relative position taaki same pata laga sake
                            }
                        }
                    }
                    st.insert(island);
                }
            }
        }
        return st.size();
    }
};
