#include <string>
using namespace std;

class Solution {
public:

    void encode(string &s){
        char start = 'A';
        int encoded[280] = {0};
        for(auto ch : s){
            if(encoded[ch]==0){
                encoded[ch]=start;
                start++;
            }
        }
        for(int i=0;i<s.length();i++){
            s[i]=encoded[s[i]];
        }
    }

    bool isIsomorphic(string s, string t) {
        encode(s);
        encode(t);
        if(s==t)
        return true;
        else
        return false;
    }
};