# include<iostream>
# include<vector>
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

     bool isMirrorTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }if(p && q){
            return (p->val==q->val) && isMirrorTree(p->left, q->right) && isMirrorTree(p->right, q->left);
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
         if(root==NULL)
         return true;
         return isMirrorTree(root->left, root->right);
    }
};