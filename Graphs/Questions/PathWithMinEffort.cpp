# include <iostream>
# include <queue>
using namespace std;

class Solution {
    public:
    
        bool isSafe(int &newX, int &newY, int &row, int &col, vector<vector<int>> &diff, int &currX, int &currY){
            if(newX>=0 && newX<row && newY>=0 && newY<col && diff[currX][currY]<diff[newX][newY]){
                return true;
            }else{
                return false;
            }
        }
    
        int minimumEffortPath(vector<vector<int>>& heights) {
            vector<vector<int>> diff(heights.size(), vector<int> (heights[0].size(), INT_MAX));
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
            int drow[4] = {0,1,0,-1};
            int dcol[4] = {1,0,-1,0};
            int row=heights.size();
            int col=heights[0].size();
    
            //initial state
            //src distance as zero
            diff[0][0]=0;
            q.push({0,{0,0}});
    
            while(!q.empty()){
                auto topPair=q.top();
                q.pop();
                auto currIndex=topPair.second;
                auto currDiff=topPair.first;
                int currX = currIndex.first;
                int currY = currIndex.second;
                for(int i=0;i<4;i++){
                    int newX = currX+drow[i];
                    int newY = currY+dcol[i];
                    if(isSafe(newX, newY, row, col, diff, currX, currY)){
                        int maxDiff = max(currDiff, abs(heights[currX][currY]-heights[newX][newY]));
                        // check updation
                        diff[newX][newY] = min(diff[newX][newY], maxDiff);
                        //create entry in new heap
                        if(newX!=row-1 || newY!=col-1){
                            q.push({diff[newX][newY],{newX,newY}});
                        }
                    }
                }
            }
            return diff[row-1][col-1];
        }
    };