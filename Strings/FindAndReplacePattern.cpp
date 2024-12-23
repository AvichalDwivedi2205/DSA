#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    void createMapping(string &str){
        char start = 'A';
        char mapping[300] = {0};
        for(auto ch:str){
            if(mapping[ch]==0){
                mapping[ch]=start;
                start++;
            }
        }

        for(int i=0;i<str.length();i++){
            str[i]=mapping[str[i]];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        createMapping(pattern);
        vector <string> ans;
        for(auto str:words){
            string temp = str;
            createMapping(temp);
            if(temp==pattern){
                ans.push_back(str);
            }
        }
        return ans;
    }
};