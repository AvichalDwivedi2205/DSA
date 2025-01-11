# include <iostream>
# include <queue>
using namespace std;

class Solution {
public:

    class compare{
        public:
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            int distA=a.first*a.first+a.second*a.second;
            int distB=b.first*b.first+b.second*b.second;
            return distA>distB;
            //Creating a min heap based on giving higher priority to lower distance from origin
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //We can create a min heap for distance and store it. Then we can retur the first k elements.
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        vector<vector<int>>ans;
        for(int i=0; i<points.size(); i++){
            pq.push({points[i][0], points[i][1]});
        }
        while(!pq.empty() && k--){
            auto top = pq.top();
            ans.push_back({top.first, top.second});
            pq.pop();
        }
        return ans;
    }
};