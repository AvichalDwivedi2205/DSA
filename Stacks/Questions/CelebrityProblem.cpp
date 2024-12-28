# include<iostream>
# include<stack>
# include<vector>
using namespace std;

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        
        //The first approach would be that the row of the celebrity will be zero
        //Ans it's column will be 1 so we will check row and column of each and find out.
        //This is the brute force approach.
        
        //This is the optimised apprach
        //Put all people in stack
        //we will take out 2 people and check if a knows b
        //if a knows b we will remove a and push back b
        //if b knows a we will remove b and push back a
        //we will keep on comparing it like this till stack becomes one-sized
        //That single person in the stack might be a celebrity
        //Then we will use desi tarika of iterating rows and columns to check
        
        stack<int> st;
        for(int i=0;i<mat.size();i++){
            st.push(i);
        }
        while(st.size()!=1){
            int a=st.top(); st.pop();
            int b=st.top(); st.pop();
            if(mat[a][b]){
                st.push(b);
            }else{
                st.push(a);
            }
        }
        int ans=st.top(); st.pop();
        for(int i=0;i<mat.size();i++){
            if(mat[ans][i]==1)
            return -1;
            if(ans==i)
            continue;
            if(mat[i][ans]==0)
            return-1;
        }
        return ans;
    }
};