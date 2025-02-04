# include <iostream>
# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int totCount=0;
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    totCount++;
                }if(grid[i][j]==2){
                    totCount++;
                    count++;
                    q.push({{i,j},0});
                }
            }
        }
        int tm=0;
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(t,tm);
            for(int i=0;i<4;i++){
                int nrow=drow[i]+r;
                int ncol=dcol[i]+c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    grid[nrow][ncol] = 2;
                    count++;
                }
            }
        }
        return count==totCount ? tm : -1;
    }
};