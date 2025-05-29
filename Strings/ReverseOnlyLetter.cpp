#include <iostream>
using namespace std;

class Solution {
public:
    // Function to reverse only the letters in the string
    string reverseOnlyLetters(string s) {
        int i = 0;                  // Start pointer
        int j = s.length() - 1;     // End pointer

        // Loop until the two pointers meet or cross
        while (j > i) {
            // If s[i] is not a letter, move i forward
            if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
                i++;
            }
            // If s[j] is not a letter, move j backward
            else if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))) {
                j--;
            }
            // Both s[i] and s[j] are letters — swap them
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;  // Return the modified string
    }
};
