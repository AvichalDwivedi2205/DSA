# include <iostream>
# include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Too fucking easy
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int n=image.size();
        int m=image[0].size();
        int startPixel=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=drow[i]+r;
                int nc=dcol[i]+c;
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]!=color && image[nr][nc]==startPixel){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};