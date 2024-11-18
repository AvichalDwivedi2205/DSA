# include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int n=row*col;
        int s=0,e=n-1,mid=s+(e-s)/2;

        while(e>=s){
            int rowIndex=mid/col;
            int colIndex=mid%col;
            int currNumber = matrix[rowIndex][colIndex];

            if(currNumber == target)
            return true;
            else if(target > currNumber)
            s=mid+1;
            else
            e=mid-1;
            mid=s+(e-s)/2;
        }
        return false;
    }
};