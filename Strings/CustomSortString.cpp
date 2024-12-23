#include <string>
using namespace std;
#include <algorithm>

class Solution {
public:
    static string str;
    static bool compare(char char1, char char2){
        return (str.find(char1)<str.find(char2));
        //This will return truw if position of char1 in str is less than position of char2 in str.
        //When true is returned then the character 1 will be placed before character2 in sorting as well 
    } 

    string customSortString(string order, string s) {
        str=order;
        sort (s.begin(), s.end(), compare);
        return s;
    }
};
string Solution::str;