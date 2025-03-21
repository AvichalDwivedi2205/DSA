#include <string>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        // crete mapping
        char start = 'a';
        char mapping[280] = {0};
        for(auto ch: key){
            if(ch != ' ' && mapping[ch]==0){
                mapping[ch] = start;
                start++;
            }
        }

        //use mapping
        string ans;
        for(int i=0; i<message.length(); i++){
            char ch = message[i];
            if(ch == ' ')
            ans.push_back(' ');
            else{
                char decodedChar = mapping[ch];
                ans.push_back(decodedChar);
            }
        }
        return ans;
    }
};