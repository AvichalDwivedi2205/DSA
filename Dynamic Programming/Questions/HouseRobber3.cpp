# include<iostream>
# include <vector>
# include <unordered_map>
using namespace std;


// Definition for a binary tree node.
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

    int solveRecursion(TreeNode* root){
        if(root==NULL) return 0;
        int include=root->val;
        if(root->left) include+=solveRecursion(root->left->left) + solveRecursion(root->left->right);
        if(root->right) include+=solveRecursion(root->right->left) + solveRecursion(root->right->right);
        int exclude=0+solveRecursion(root->left)+solveRecursion(root->right);
        return max(include, exclude);
    }

    int solveMemo(TreeNode* root, unordered_map <TreeNode*, int> &mp){
        if(root==NULL) return 0;
        if(mp.find(root)!=mp.end()) return mp[root];
        int include=root->val;
        if(root->left) include+=solveMemo(root->left->left, mp) + solveMemo(root->left->right, mp);
        if(root->right) include+=solveMemo(root->right->left, mp) + solveMemo(root->right->right, mp);
        int exclude=0+solveMemo(root->left, mp)+solveMemo(root->right, mp);
        return mp[root]=max(include, exclude);
    }

    int rob(TreeNode* root) {
        // easy as fuck
        unordered_map <TreeNode*, int> mp;
        return solveMemo(root, mp);
    }
};