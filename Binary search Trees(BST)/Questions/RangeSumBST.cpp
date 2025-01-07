#include <iostream>
#include <vector>
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

    void sumTree(TreeNode* root, int low, int high, int &sum){
        if(root==NULL) return;
        if(root->val>=low && root->val<=high){
            sum=sum+root->val;
            sumTree(root->left, low, high, sum);
            sumTree(root->right, low, high, sum);
        }else if(root->val<low){
            sumTree(root->right, low, high, sum);
        }else{
            sumTree(root->left, low, high, sum);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        //If in range call that node and then recursively for left and right
        //If less then only call for right
        //If more then only call for left
        int sum=0;
        sumTree(root, low, high, sum);
        return sum;
    }
};