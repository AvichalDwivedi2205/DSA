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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==p->val){
            return p;
        }
        if(root->val==q->val){
            return q;
        }
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        if(leftAns == NULL && rightAns==NULL){
            return NULL;
        }else if(leftAns != NULL && rightAns==NULL){
            return leftAns;
        }else if(leftAns == NULL && rightAns!=NULL){
            return rightAns;
        }else{
            return root;
        }
    }
};