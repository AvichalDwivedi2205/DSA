# include <iostream>
# include <queue>
# include <stack>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q; // Queue to store indices of characters
        int freq[26] = {0}; // Frequency array for lowercase letters

        // Populate frequency array and queue
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch - 'a']++;
            q.push(i); // Push the index into the queue
        }

        // Process the queue to find the first unique character
        while (!q.empty()) {
            int idx = q.front(); // Get the front index
            
            // Check if the character at this index is unique
            if (freq[s[idx] - 'a'] > 1) {
                q.pop(); // Return the index of the first unique character
            }else{
                return idx;
            }
            
            // Pop if the character is not unique
        }

        return -1; // No unique character found
    }
};
