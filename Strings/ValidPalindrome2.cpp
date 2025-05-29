#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    
    // Helper function to check if a substring s[i..j] is a palindrome
    bool checkPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i] == s[j]) {
                i++;
                j--;
            } else {
                // Characters don't match, not a palindrome
                return false;
            }
        }
        return true; // All characters matched
    }

    // Main function to check if the string can become a palindrome
    // by removing at most one character
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        // Use two-pointer approach to compare characters
        while(i < j){
            if(s[i] == s[j]) {
                // Characters match, move both pointers inward
                i++;
                j--;
            } else {
                // Mismatch found: try removing either s[i] or s[j]
                bool ans1 = checkPalindrome(s, i + 1, j); // Skip left character
                bool ans2 = checkPalindrome(s, i, j - 1); // Skip right character

                // Return true if either of the two substrings is a palindrome
                return ans1 || ans2;
            }
        }

        // If the loop completes with no mismatches, it's already a palindrome
        return true;
    }
};
