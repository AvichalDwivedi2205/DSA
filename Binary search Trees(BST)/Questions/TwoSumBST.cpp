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

    void storeInorder (TreeNode* root, vector<int> &v){
        if(root==NULL){
            return;
        }
        storeInorder(root->left, v);
        v.push_back(root->val);
        storeInorder(root->right, v);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        storeInorder(root, inorder);
        int s=0, e=inorder.size()-1;
        while(s<e){
            int sum=inorder[s]+inorder[e];
            if(sum==k){
                return true;
            }else if(sum>k){
                e--;
            }else{
                s++;
            }
        }
        return false;
    }
};