# include <iostream>
# include <queue>
using namespace std;

class Solution {
public:
    // This is method 1 using dfs approach
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int row, int col, int drow[], int dcol[]){
        vis[row][col]=true;
        for(int i=0;i<4;i++){
            int nr=row+drow[i];
            int nc=col+dcol[i];
            int n=grid.size();
            int m=grid[0].size();
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                dfs(grid,vis,nr,nc,drow,dcol);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        // Easy as fuck i guess
        int n=grid.size();
        int m=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(grid,vis,i,0,drow,dcol);
            }if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(grid,vis,i,m-1,drow,dcol);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(grid,vis,0,i,drow,dcol);
            }if(grid[n-1][i]==1 && !vis[n-1][i]){
                dfs(grid,vis,n-1,i,drow,dcol);
            }
        }
        int count=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};

class Solution2 {
public:
    // This is method 2 
    // We will now use multi source bfs
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
         for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                vis[i][0]=true;
            }if(grid[i][m-1]==1){
                q.push({i,m-1});
                vis[i][m-1]=true;
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                q.push({0,i});
                vis[0][i]=true;
            }if(grid[n-1][i]==1){
                q.push({n-1,i});
                vis[n-1][i]=true;
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=true;
                }
            }
        }
        int count=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};