# include <string>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
  public:
    bool isSafe(vector<vector<int>> &mat, int newx, int newy, int row, int col, vector<vector<bool>> &visited) {
        return (newx >= 0 && newx < row && newy >= 0 && newy < col && mat[newx][newy] == 1 && !visited[newx][newy]);
    }

    void solve(vector<vector<int>> &mat, int row, int col, int srcx, int srcy, vector<string> &ans, string &output, vector<vector<bool>> &visited) {
        if (srcx == row - 1 && srcy == col - 1) {
            ans.push_back(output);
            return;
        }

        // Mark visited
        visited[srcx][srcy] = true;

        // UP
        if (isSafe(mat, srcx - 1, srcy, row, col, visited)) {
            output.push_back('U');
            solve(mat, row, col, srcx - 1, srcy, ans, output, visited);
            output.pop_back();
        }

        // DOWN
        if (isSafe(mat, srcx + 1, srcy, row, col, visited)) {
            output.push_back('D');
            solve(mat, row, col, srcx + 1, srcy, ans, output, visited);
            output.pop_back();
        }

        // RIGHT
        if (isSafe(mat, srcx, srcy + 1, row, col, visited)) {
            output.push_back('R');
            solve(mat, row, col, srcx, srcy + 1, ans, output, visited);
            output.pop_back();
        }

        // LEFT
        if (isSafe(mat, srcx, srcy - 1, row, col, visited)) {
            output.push_back('L');
            solve(mat, row, col, srcx, srcy - 1, ans, output, visited);
            output.pop_back();
        }

        // Backtrack
        visited[srcx][srcy] = false;
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<string> ans;
        string output = "";

        if (mat[0][0] == 0) {
            return ans;
        }

        solve(mat, row, col, 0, 0, ans, output, visited);
        return ans;
    }
};
