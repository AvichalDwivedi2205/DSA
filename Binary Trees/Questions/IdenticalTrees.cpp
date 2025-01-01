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
    void traversalP(TreeNode* root, vector<int> &ptraversal){
        if(root==NULL){
            return;
        }
        ptraversal.push_back(root->val);
        traversalP(root->left, ptraversal);
        ptraversal.push_back(INT_MIN);
        traversalP(root->right, ptraversal);

    }
    void traversalQ(TreeNode* root, vector<int> &qtraversal){
         if(root==NULL){
            return;
        }
        qtraversal.push_back(root->val);
        traversalQ(root->left, qtraversal);
        qtraversal.push_back(INT_MIN);
        traversalQ(root->right, qtraversal);

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector <int> ptraversal;
        vector <int> qtraversal;
        traversalP(p, ptraversal);
        traversalQ(q, qtraversal);
        if(ptraversal.size()!=qtraversal.size()){
            return false;
        }
        for(int i=0;i<ptraversal.size();i++){
            if(ptraversal[i]!=qtraversal[i])
            return false;
        }
        return true;
    }
};

class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }if(p && q){
            return (p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;
    }
};