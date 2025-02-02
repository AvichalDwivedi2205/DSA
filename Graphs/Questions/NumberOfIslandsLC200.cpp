# include<vector>
# include <unordered_map>
# include <iostream>
using namespace std;

class SolutionM1 {
public:

    bool  dfs(vector<vector<char>>& grid, int i, int j, int &m, int &n){
        // out of range check and water check will be required
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0' || grid[i][j]=='x'){
            return 0;
        }
        grid[i][j]='x';
        bool marked=1;

        bool baakiKaAns = dfs(grid,i-1,j,m,n) | dfs(grid,i+1,j,m,n) | dfs(grid,i,j-1,m,n) | dfs(grid,i,j+1,m,n);
        // Bitwise worked because it forces all the operands to be operated and does not stop just after the first is true or false
        return marked||baakiKaAns;
    }
 
    int numIslands(vector<vector<char>>& grid) {
        // This is not directly a question of graphs but we can apply depth first search over here
        // Lessgo
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0; // no. of islands
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='x' || grid[i][j]=='0') continue;
                ans+=dfs(grid, i, j, m, n);
            }
        }
        return ans;
    }
};

class SolutionM2 {
public:
    // Make dfs a void function since we don't really need to return a value.
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        // Boundary checks and water/visited cell check.
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || grid[i][j] == 'x')
            return;
        
        // Mark the cell as visited.
        grid[i][j] = 'x';
        
        // Recurse on all four directions.
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();

        int ans = 0; // Number of islands.
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1') {  // Unvisited land cell.
                    dfs(grid, i, j, m, n);
                    ans++;  // Count one island.
                }
            }
        }
        return ans;
    }
};
