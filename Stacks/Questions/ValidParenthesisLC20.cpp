# include<iostream>
# include <stack>
using namespace std;

class Solution {
public:

    bool check(char a, char b){
        if((a=='(' && b==')')||(a=='{' && b=='}')||(a=='[' && b==']'))
        return true;
        else
        return false;
    }

    bool isValid(string s) {
        stack <char> st;
        if(s.length()==0){
            return true;
        }
        st.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(st.empty() || !check(st.top(),s[i])){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
        if(st.empty())
        return true;
        else
        return false;
    }
};