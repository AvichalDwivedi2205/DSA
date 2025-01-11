# include <iostream>
# include <queue>
using namespace std;

class Solution {
public:
# define ll long long 
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        vector<ll> prefix(nums.size(), -1), suffix(nums.size(), -1);
        //Prefix[i] stores the sum of first n elements from left side
        //suffix[i] stores the sum of first n elements from right side
        priority_queue<ll> pq;
        ll sum=0;//minimum n element sum
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            pq.push(nums[i]);
    
            //pop out max elements
            if(pq.size()>n){
                sum -=pq.top();
                pq.pop();
            }
            if(pq.size()==n){
                prefix[i]=sum;
            }
        }
        sum=0;//maximum n element sum so we need a min heap
        priority_queue<ll, vector<ll>, greater<ll>> pq2;// min heap
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            pq2.push(nums[i]);

            //pop out min elements
            if(pq2.size()>n){
                sum -=pq2.top();
                pq2.pop();
            }
            if(pq2.size()==n){
                suffix[i]=sum;
            }
        }

        ll ans=LLONG_MAX;
        for(int i=n-1; i<2*n;i++){
            ans=min(ans, prefix[i]-suffix[i+1]);
        }
        return ans;
    }
};