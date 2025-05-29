#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();          // Number of rows
        int col = matrix[0].size();       // Number of columns

        int n = row * col;                // Total number of elements in the matrix
        int s = 0, e = n - 1;             // Start and end for binary search over 1D space
        int mid = s + (e - s) / 2;

        while (e >= s) {
            // Convert 1D mid index to 2D matrix coordinates
            int rowIndex = mid / col;     // Row number
            int colIndex = mid % col;     // Column number

            int currNumber = matrix[rowIndex][colIndex]; // Current number at (rowIndex, colIndex)

            // Check if current number matches the target
            if (currNumber == target)
                return true;

            // If target is greater, search in the right half
            else if (target > currNumber)
                s = mid + 1;

            // If target is smaller, search in the left half
            else
                e = mid - 1;

            // Update mid for the next iteration
            mid = s + (e - s) / 2;
        }

        // If not found after loop, return false
        return false;
    }
};
