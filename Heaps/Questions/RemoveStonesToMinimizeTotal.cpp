# include <iostream>
# include <queue>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(k--){
            int ele=pq.top();
            pq.pop();
            if(ele&1) ele=ele/2 + 1;else ele=ele/2;
            pq.push(ele);
        }
        int sum=0;
        while(!pq.empty()){
            sum=sum+pq.top();
            pq.pop();
        }
        return sum;
    }
};