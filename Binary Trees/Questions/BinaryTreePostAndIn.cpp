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

class Solution {
public:

    void createmapping(vector<int> &inorder, map <int, int> &mp){
        for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;
    }

    TreeNode* solve(vector<int>& postorder,int &postindex, vector<int>& inorder, int inStart, int inEnd, int size, map <int, int> &mp){
        if(postindex<0 || inStart>inEnd){
            return NULL;
        }
        //1 case i will solve and rest recursion
        int ele = postorder[postindex];
        postindex--;
        TreeNode* root = new TreeNode(ele);
        int position=mp[ele];
        root->right=solve(postorder, postindex, inorder, position+1, inEnd, size, mp);
        root->left=solve(postorder, postindex, inorder, inStart, position-1, size, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postindex=postorder.size()-1;
        map <int, int> mp;
        createmapping(inorder, mp);
        return solve(postorder, postindex, inorder, 0, inorder.size()-1, inorder.size(), mp);
    }
};