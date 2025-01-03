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

    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        int ans=max(leftHeight, rightHeight)+1;
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        // This solution is bad as we are going to all nodes and checking heights.
        if (root==NULL){
            return true;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff=abs(leftHeight-rightHeight);
        bool currNodeAns=(diff<=1);
        bool leftAns=isBalanced(root->left);
        bool rightAns=isBalanced(root->right);
        if(leftAns && rightAns && currNodeAns){
            return true;
        }else{
            return false;
        }
    }
};

class Solution2 {
public:
    bool isbalanced=true;
    int height(TreeNode * root) {
        if (root==NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        if(isbalanced && abs(lh-rh)>1){
            isbalanced=false;
        }
        return max(lh,rh)+1;
    }

    bool isBalanced(TreeNode* root) {
        height(root);
        return isbalanced;
    }
};