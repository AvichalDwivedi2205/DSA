# include <iostream>
# include <queue>
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
    bool levelOrderTraversal(TreeNode* root){
        if(root==NULL) return true;
        queue<TreeNode*> q;
        int flag=0;
        q.push(root);
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            if(ele->left!=NULL){
                if(flag) return false;
                q.push(ele->left);
            }else{
                flag=1;
            }
            if(ele->right!=NULL){
                if(flag) return false;
                q.push(ele->right);
            }else{
                flag=1;
            }
        }
        return true;
    }

    bool isCompleteTree(TreeNode* root) {
        return levelOrderTraversal(root);
    }
};