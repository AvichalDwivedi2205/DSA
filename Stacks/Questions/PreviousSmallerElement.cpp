# include<iostream>
# include <stack>
# include <vector>
using namespace std;

class Solution {
  public:
    vector<int> PreviousSmaller(vector<int>& arr) {
        //  code here
        stack <int> st;
        vector<int> ans(arr.size());
        st.push(-1);
        for(int i=0;i<arr.size();i++){
            int curr=arr[i];
            while(st.top()>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(curr);
        }
        return ans;
    }
};