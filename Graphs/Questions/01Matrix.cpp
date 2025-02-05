# include <vector>
# include <queue>
using namespace std;

class Solution {
public:

    vector<vector<int>> TLEApproach(vector<vector<int>>& mat){
        queue<pair<int,int>> q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=0){
                    q.push({i,j});
                }
            }
        }
        int drow[]={1,0,-1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int found=0,count=0;
            while(found==0){
                count++;
                for(int i=0;i<4;i++){
                    int crow=r+drow[i]+count-1;
                    int ccol=c+dcol[i]+count-1;
                    if(crow>=0 && crow<n && ccol>=0 && ccol<m){
                        if(mat[crow][ccol]==0){
                            found=1;
                            break;
                        }else{
                            continue;
                        }
                    }
                }
                ans[r][c]=count;
            }
        }
        return ans;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    mat[i][j]=2;
                    ans[i][j]=0;
                }
            }
        }
        int drow[]={1,0,-1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int closest=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]!=2){
                    q.push({{nr,nc},closest+1});
                    ans[nr][nc]=closest+1;
                    mat[nr][nc]=2;
                }
            }
        }
        return ans;
    }
};