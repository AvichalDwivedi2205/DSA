#include <string>
using namespace std;

class Solution {
public:
    // Helper function to expand around center and count palindromes
    int expand(string s, int i, int j) {
        int count = 0;

        // Expand as long as i and j are within bounds and characters match
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            count++;    // Found a palindrome
            i--;        // Move left
            j++;        // Move right
        }

        return count;
    }

    // Main function to count all palindromic substrings in the string
    int countSubstrings(string s) {
        int totalPalin = 0;

        // For each character in the string, try to expand around it
        for (int i = 0; i < s.length(); i++) {
            // Count odd-length palindromes (centered at one character)
            int oddPalin = expand(s, i, i);

            // Count even-length palindromes (centered between two characters)
            int evenPalin = expand(s, i, i + 1);

            // Add both to the total count
            totalPalin += oddPalin + evenPalin;
        }

        return totalPalin;
    }
};
