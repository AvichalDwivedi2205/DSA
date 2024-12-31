# include<iostream>
# include<vector>
# include<map>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

    void createmapping(vector<int> &inorder, map <int, int> &mp){
        for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;
    }

    TreeNode* solve(vector<int>& preorder,int &preindex, vector<int>& inorder, int inStart, int inEnd, int size, map <int, int> &mp){
        if(preindex>=size || inStart>inEnd){
            return NULL;
        }
        //1 case i will solve and rest recursion
        int ele = preorder[preindex];
        preindex++;
        TreeNode* root = new TreeNode(ele);
        int position=mp[ele];
        root->left=solve(preorder, preindex, inorder, inStart, position-1, size, mp);
        root->right=solve(preorder, preindex, inorder, position+1, inEnd, size, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex=0;
        map <int, int> mp;
        createmapping(inorder, mp);
        return solve(preorder, preindex, inorder, 0, inorder.size()-1, inorder.size(), mp);
    }
};