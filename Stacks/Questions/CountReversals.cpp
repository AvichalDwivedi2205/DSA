# include<iostream>
# include<stack>
# include<string>
using namespace std;

int count(string s){
    // your code here
    if(s.size()&1){
        return -1;
    }
    int reversal=0;
    stack <char> st;
    for(char ch:s){
        if(ch=='{'){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top()=='{'){
                st.pop();            
            }
            else
            st.push(ch);
        }
    }
    while(!st.empty()){
        char a=st.top(); st.pop();
        char b=st.top(); st.pop();
        if(a==b)
        reversal++;
        else
        reversal+=2;
    }
    return reversal;
}