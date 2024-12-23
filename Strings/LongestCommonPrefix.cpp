#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix = strs[0];
        for(int i=1;i<strs.size();i++){
            string temp=strs[i];
            string tempPrefix="";
            for(int j=0;j<temp.length();j++){
                if(temp[j]==commonPrefix[j])
                tempPrefix+=commonPrefix[j];
                else
                break;
            }
            commonPrefix=tempPrefix;
            if(commonPrefix=="")
            break;
        }
        return commonPrefix;
    }
};