# include <iostream>
# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
   
    void dfs(vector<vector<char>>& board, vector<vector<bool>> & vis, int row, int col, int drow[], int dcol[]){
        vis[row][col]=true;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nr=row+drow[i];
            int nc=col+dcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O'&&!vis[nr][nc]){
                dfs(board,vis,nr,nc,drow,dcol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(board,vis,i,0,drow,dcol);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
               dfs(board,vis,i,m-1,drow,dcol);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(board,vis,0,i,drow,dcol);
            }
            if(board[n-1][i]=='O' && !vis[n-1][i]){
                dfs(board,vis,n-1,i,drow,dcol);
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};