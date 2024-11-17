#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int r=m.size();
        int c=m[0].size();
        int total_elements = r*c;
        vector <int> ans;

        int startRow=0;
        int endCol=c-1;
        int startCol=0;
        int endRow=r-1;
        int count=0;
        while(count<total_elements){
            //stating row
            for(int i=startCol; i<=endCol && count<total_elements; i++){
                ans.push_back(m[startRow][i]);
                count++;
            }
            startRow++; 
            //ending column
            for(int i=startRow; i<=endRow && count<total_elements; i++){
                ans.push_back(m[i][endCol]);
                count++;
            }
            endCol--;
            //ending row
            for(int i=endCol;i>=startCol && count<total_elements;i--){
                ans.push_back(m[endRow][i]);
                count++;
            }
            endRow--;
            //starting column
            for(int i=endRow;i>=startRow && count<total_elements;i--){
                ans.push_back(m[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};