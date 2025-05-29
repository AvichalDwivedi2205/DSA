#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Static string to hold the custom order for comparison
    static string str;

    // Comparator function to decide order of characters based on their position in 'str'
    static bool compare(char char1, char char2) {
        // Find positions of char1 and char2 in str
        // Characters that appear earlier in str come first
        return (str.find(char1) < str.find(char2));
    }

    // Function to sort string 's' according to custom order given in 'order'
    string customSortString(string order, string s) {
        str = order;                    // Assign the custom order to static string
        sort(s.begin(), s.end(), compare);  // Sort string s using the custom comparator
        return s;                      // Return the sorted string
    }
};
