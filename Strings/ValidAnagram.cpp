#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        short snum[300] = {0};
        short tnum[300] = {0};
        if(s.length()!=t.length())
        return false;
        else{
            for(int i=0;i<s.length();i++){
                snum[s[i]]++;
                tnum[t[i]]++;
            }
            for(int i=0;i<s.length();i++){
                if(snum[s[i]]==tnum[s[i]])
                continue;
                else
                return false;
            }
            return true;
        }
    }
};