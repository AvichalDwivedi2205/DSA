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

    TreeNode* build(int min, int max, int &i, vector<int>& preorder){
        if(i>=preorder.size()){
            return NULL;
        }
        TreeNode* root=nullptr;
        if(preorder[i]>min && preorder[i]<max){
            root=new TreeNode(preorder[i]);
            i++;
            //The above 2 lines is same as root=new TreeNode(preorder[i++]);
            root->left=build(min,root->val,i, preorder);
            root->right=build(root->val, max, i, preorder);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Brute force approach would be to traverse formt he node all the times 
        //In this case it would be complexity of O(nsquared)

        // Another method would be to find the inorder traversal of the following.
        // Then we will use the sorted LL to construct the given BST
        // Time complexity would be O(nlogn+n) ans space of O(n)

        // Now we will see the best method for this particular question
        // We will us ethe approach of range in this case
        // For example let us say that the root node is 7 then the range of the element left to it would be
        // (7,inf) and taht of left would be (-inf, 7)
        // There owuld be anothe rcase in this though
        // Let us say 5 is an element in the left of a BST. The in that case the right of it would have a range
        // (5, the node just before that) and left would have a range of (-inf, 5)
        // The right subtree case would just be reversed in this case.

        int min=INT_MIN;
        int max=INT_MAX;
        int i=0;
        return build(min, max, i, preorder);
    }
};