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
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> NextSmaller(vector<int>& arr) {
        //  code here
        stack <int> st;
        vector<int> ans(arr.size());
        st.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        // In this we will use the next smaller and previous smaller element code and the answer of width will be next-prev-1
        vector<int> next=NextSmaller(heights);
        for(int i=0;i<next.size();i++){
            if(next[i]==-1){
                next[i]=heights.size();
            }
        }
        vector<int> prev=PreviousSmaller(heights);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            int area=heights[i]*(next[i]-prev[i]-1);
            maxi=max(area,maxi);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            vector <int> t;
            for(int j=0;j<m;j++){
                t.push_back(matrix[i][j] - '0');
            }
            v.push_back(t);
        }
        int area=largestRectangleArea(v[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]){
                    v[i][j]+=v[i-1][j];
                }else{
                    v[i][j]=0;
                }
            }
            area=max(area, largestRectangleArea(v[i]));
        }
        return area;
    }
};