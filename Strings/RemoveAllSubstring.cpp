#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            //if not equal to npos then it means that particular part still exist in string
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};