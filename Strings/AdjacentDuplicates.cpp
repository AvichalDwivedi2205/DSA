#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string snew="";
        int j=0;
        while(j<s.length()){
            if(snew.length()>0 && snew[snew.length()-1]==s[j]){
                snew.pop_back();
            }else{
                snew.push_back(s[j]);
            }
            j++;
        }
        return snew;
    }
};