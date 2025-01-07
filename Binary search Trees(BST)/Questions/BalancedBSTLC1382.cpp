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

    void inorder(TreeNode* root, vector<int> &in){
        if(root==NULL){
            return;
        }
        //LNR
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    TreeNode* buildTree(vector<int> &in, int s, int e){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left=buildTree(in, s, mid-1);
        root->right=buildTree(in, mid+1, e);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        //One simple way to approach this would be to have an inorder traversal ad then construct a BST from that
        // Simple
        vector<int> in;
        inorder(root, in);

        // Build a BST Using inorder traversal
        return buildTree(in, 0, in.size()-1);
    }
};