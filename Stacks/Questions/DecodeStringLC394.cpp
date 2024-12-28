# include<iostream>
# include<stack>
# include<string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack <string> st;
        for(char ch:s){
            if(ch==']'){
                string temp="";
                while(!st.empty() && st.top()!="["){        
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                string number="";
                while(!st.empty() && isdigit(st.top()[0])){
                    number+=st.top();
                    st.pop();
                }
                reverse(number.begin(), number.end());
                int n=stoi(number);

                string currentCode="";
                while(n--){
                    currentCode+=temp;
                }
                st.push(currentCode);
            }else{
                string temp(1,ch);
                st.push(temp);
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};