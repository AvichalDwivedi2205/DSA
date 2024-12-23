#include <string>
using namespace std;

class Solution {
public:

    int expand(string s, int i, int j){
        int count = 0;
        while(i>=0 && j<=s.length()-1 && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int totalPalin = 0;
        for(int i=0;i<s.length();i++){
            int oddPalin = expand(s,i,i);
            int evenPalin = expand(s,i,i+1);
            totalPalin+= oddPalin + evenPalin;
        }
        return totalPalin;
    }
};