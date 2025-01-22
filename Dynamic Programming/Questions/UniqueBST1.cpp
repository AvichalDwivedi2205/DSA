# include<iostream>
# include <vector>
# include <map>
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

    vector<TreeNode*> solveRecursion(int start, int end){
        // Base Case
        if(start>end) return {NULL};
        if(start==end){
            TreeNode* x = new TreeNode(start);
            return {x};
        }
        
        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*>left=solveRecursion(start,i-1);
            vector<TreeNode*>right=solveRecursion(i+1,end);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    map<pair<int, int>, vector<TreeNode*>>dp;
    vector<TreeNode*> solveMemo(int start, int end){
        // Base Case
        if(start>end) return {NULL};
        if(start==end){
            TreeNode* x = new TreeNode(start);
            return {x};
        }
        if(dp.find({start,end})!=dp.end()) return dp[{start,end}];
        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*>left=solveRecursion(start,i-1);
            vector<TreeNode*>right=solveRecursion(i+1,end);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];
                    ans.push_back(root);
                }
            }
        }
        return dp[{start,end}]=ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return solveMemo(1, n);
    }
};