# include <iostream>
# include <queue>
# include <vector>
using namespace std;

class Solution {
public:

    vector<int> maxSlidingWindowMyMethod(vector<int>& nums, int k) {
        queue<int> q;
        vector <int> v(nums.size()-k+1, 0);
        int maxi=INT_MIN;
        int index=0;
        for(int i=0;i<k;i++){
            if(nums[i]>maxi){
                index=i;
                maxi=nums[i];
            }
        }
        q.push(index);
        v[0]=maxi;
        for(int i=k;i<nums.size();i++){
            if(i-q.front()>=k){
                q.pop();
                maxi=INT_MIN;
                for(int j=i-k+1;j<=i;j++){
                    if(nums[j]>maxi){
                        index=j;
                        maxi=nums[j];
                    }
                }
                v[i-k+1]=maxi;
                q.push(index);
            }else{
                maxi=v[i-k];
                v[i-k+1]=max(maxi,nums[i]);
            }
        }
        return v;
    }
    // The first one was my method but the time limit exceeded so we neet a better solution i guess.

    // This solution is very nice as compared to the previous one. 
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;
        int size = nums.size();
        // first window process till k size
        for (int i = 0; i < k; i++)
        {
            int ele = nums[i];
            // push elements in the queue and remove chote vale elements
            while (!dq.empty() && ele > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // processs the remaining window Removal and Insertion
        for (int i = k; i < size; i++)
        {

            ans.push_back(nums[dq.front()]);

            // remove
            if (i - dq.front() >= k)
                dq.pop_front();
            int ele = nums[i];
            // push elements in the queue and remove chote vale elements
            while (!dq.empty() && ele > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // handle last window
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};