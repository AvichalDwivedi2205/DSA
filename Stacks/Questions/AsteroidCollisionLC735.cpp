# include<iostream>
# include<stack>
# include<vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack <int> st;
        vector <int> ans;
        for(int i=0; i<a.size();i++){
            if(st.empty())
            st.push(a[i]);
            else if(!st.empty() && st.top()>0){
                if(a[i]>0)
                st.push(a[i]);
                else{
                    if(st.top()+a[i]==0){
                        st.pop();
                        continue;
                    }
                    while(!st.empty() && st.top()>0 && (a[i]+st.top())<0){
                        st.pop();
                    }
                    if(st.empty())
                    st.push(a[i]);
                    else if(st.top()+a[i]==0){
                        st.pop();
                        continue;
                    }
                    else if(st.top()<0)
                    st.push(a[i]);
                    else
                    continue;
                }
            }else if(!st.empty() && st.top()<0){
                if(a[i]<0)
                st.push(a[i]);
                else{
                    st.push(a[i]);
                }
            }
        }
        if(st.empty())
        return ans;
        else{
            while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        }
        
    }
};