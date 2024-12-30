# include<iostream>
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
    int maxDepth(TreeNode* root) {
        // We can do this by level order traversal The code of level order traversal is in class 1 so look at that if you want to
        //Or we use recursion which would be the best approach in this case
        if (root==NULL){
            return 0;
        }
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);
        int height=max(leftDepth, rightDepth)+1;
        return height;
    }
};