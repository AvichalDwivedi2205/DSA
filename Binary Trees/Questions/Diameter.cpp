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

    //This is Brute Force Code which is not good.
    int height(TreeNode* root) {
        // We can do this by level order traversal
        //Or we use recursion which would be the best approach in this case
        if (root==NULL){
            return 0;
        }
        int leftDepth=height(root->left);
        int rightDepth=height(root->right);
        int height=max(leftDepth, rightDepth)+1;
        return height;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //base case
        if(root==NULL){
            return 0;
        }
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = height(root->left) + height(root->right);
        int diameter = max(option1 , max(option2, option3));
        return diameter;
    }
};