# include<iostream>
# include<stack>
# include<string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st;
        for(char ch:s){
            if(st.empty())
            st.push(ch);
            else if(st.top()==ch){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        string final="";
        while(!st.empty()){
            final=final+st.top();
            st.pop();
        }
        reverse(final.begin(), final.end());
        return final;
    }
};