#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string snew = "";  // This acts as a stack to build the result string without duplicates
        int j = 0;

        while (j < s.length()) {
            // Check if the last character in snew is the same as the current character in s
            if (snew.length() > 0 && snew[snew.length() - 1] == s[j]) {
                snew.pop_back();  // Remove the last character (duplicate)
            } else {
                snew.push_back(s[j]);  // Add the current character to snew
            }
            j++;  // Move to the next character
        }

        return snew;  // Return the processed string with adjacent duplicates removed
    }
};
