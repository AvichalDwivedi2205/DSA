# include<iostream>
# include <stack>
# include <vector>
using namespace std;

class Solution {
public:

    bool recursionMethod(string s){
        int fnd = s.find("abc");
        if(s.size()==0){
            return true;
        }
        if(fnd != string::npos){
            string tleft = s.substr(0, fnd);
            string tright = s.substr(fnd+3,s.size());
            return isValid(tleft + tright);
        }
        else{
            return false;
        }
    }

    bool method3(string s){
        stack<char> st;
        for (char ch : s) {
            st.push(ch);
            // Check if the top three characters form "abc"
            if (st.size() >= 3) {
                char c = st.top(); st.pop();
                char b = st.top(); st.pop();
                char a = st.top(); st.pop();

                if (a == 'a' && b == 'b' && c == 'c') {
                    // Valid "abc", do nothing (remove them from stack)
                } else {
                    // Push them back in order if not "abc"
                    st.push(a);
                    st.push(b);
                    st.push(c);
                }
            }
        }
        return st.empty(); // Stack should be empty if valid
    }

    bool isValid(string s) {
        if(s[0]!='a')
        return false;
        stack <char> st;
        for(char ch:s){
            if(ch=='a')
                st.push(ch);
            else if(ch=='b'){
                if(!st.empty() && st.top()=='a')
                st.push('b');
                else
                return false;
            }else{
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    if(!st.empty() && st.top()=='a')
                    st.pop();
                    else
                    return false;
                }else
                return false;
            }
        }
        if(st.empty())
        return true;
        else
        return false;
    }
};