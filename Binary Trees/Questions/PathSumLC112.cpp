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

    bool boolAns(TreeNode* root, int targetSum, int sum){
        if(root==NULL){
            return false;
        }
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            // I am currently standing on the leaf node
            if(sum==targetSum){
                return true;
            }else{
                return false;
            }
        }
        bool leftAns=boolAns(root->left, targetSum, sum);
        bool rightAns=boolAns(root->right, targetSum, sum);
        return leftAns||rightAns;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool boolAnswer=boolAns(root, targetSum, sum);
        return boolAnswer;
    }
};