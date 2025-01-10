# include <iostream>
# include <queue>
using namespace std;

class Solution {
public:

    class Info{
        public:
        int data;
        int rowIndex;
        int colIndex;

        Info(int data, int rowI, int colI){
            this->data = data;
            this->rowIndex = rowI;
            this->colIndex = colI;
        }
    };

    class Compare{
        public:
        bool operator()(Info* a, Info* b){
            return a->data > b->data;
            //Condition For Min Heap
            //If we make it a->data<b->data then we would have created max heap. 
        }  
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Non decreasing means ascending and equal both cases will be possible
        vector<int> ans;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        priority_queue<Info*, vector<Info*>, Compare> pq;
        for(int i=0;i<nums.size(); i++){
            Info* temp = new Info(nums[i][0], i, 0);
            pq.push(temp);
            maxi=max(maxi, nums[i][0]);
            mini=min(mini, nums[i][0]);
        }
        int ansStart=mini;
        int ansEnd=maxi;
        while(!pq.empty()){
            Info* topEle = pq.top();
            int data = topEle->data;
            int row = topEle->rowIndex;
            int col = topEle->colIndex;
            pq.pop();
            mini=topEle->data;
            //maxi ki value pehle se pari hui hai so we will now have to compare
            if((maxi-mini)<(ansEnd-ansStart)){
                ansStart=mini;
                ansEnd=maxi;
            }
            //Insertion wala step
            if(col+1<nums[row].size()){
                int newEle = nums[row][col+1];
                maxi=max(maxi, newEle);
                Info* newInfo=new Info(newEle, row, col+1);
                pq.push(newInfo);
            }else{
                //We are out of an array
                break;
            }
        }
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};