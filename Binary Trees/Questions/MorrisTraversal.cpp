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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        while(curr){
            //left node is null, then visit it and go right
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            //left Node is not Null
            else{
                //find inorder predessesor
                TreeNode* pred=curr->left;
                while(pred->right && pred->right!=curr){
                    pred=pred->right;
                }
                //If pred ight node is null then establish link from predessor to current
                if(pred->right == NULL){
                    pred->right=curr;
                    curr=curr->left;
                }else{
                    //left is already visited you can go right after visiting curr node, while removing the link
                    pred->right=nullptr;
                    ans.push_back(curr->val);
                    curr=curr->right;
                } 
            }
        }
        return ans;
    }
};