# include<iostream>
using namespace std;
# include <vector>

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

    void solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> temp, int sum) {
        if(root==NULL){
            return;
        }
        //1 Case solve karna hai
        sum+=root->val;
        temp.push_back(root->val);
        //extra case when the node becomes leaf node
        if(root->right==NULL && root->left==NULL){
            if(sum==targetSum){
                ans.push_back(temp);
            }else{
                return;
            }
        }
        //Baaki recursion sambhalega
        solve(root->left,targetSum,ans,temp,sum);
        solve(root->right,targetSum,ans,temp,sum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum=0;
        solve(root, targetSum, ans, temp, sum);
        return ans;
    }
};