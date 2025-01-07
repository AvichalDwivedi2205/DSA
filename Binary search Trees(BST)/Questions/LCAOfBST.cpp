#include <iostream>
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
        //Cases 1: p and q come in left of subtree
        if(p->val<root->val && q->val<root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        //Case 2: p and q both come in the right of subtree
        else if(p->val>root->val && q->val>root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        //Case 3 will be p is in left subtree and q is in right subtree
        //Case 4 will be opposite of case 3
        //In both the cases the answer will be same which is that node ony
        else{
            return root;
        }
    }
};