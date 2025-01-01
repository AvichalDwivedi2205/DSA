# include<iostream>
# include<vector>
# include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        bool l2r = true; // Flag to toggle between left-to-right and right-to-left
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int width = q.size();
            vector<int> temp(width);

            for (int i = 0; i < width; i++) {
                int index = l2r ? i : width - i - 1;

                TreeNode* front = q.front();
                q.pop();

                temp[index] = front->val;

                if (front->left != NULL) {
                    q.push(front->left);
                }
                if (front->right != NULL) {
                    q.push(front->right);
                }
            }

            ans.push_back(temp);
            l2r = !l2r; // Toggle direction for the next level
        }

        return ans;
    }
};
