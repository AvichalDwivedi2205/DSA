# include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int sum(Node* root){
        if(root==NULL){
            return 0;
        }if(!root->left && !root->right){
            int temp=root->data;
            root->data=0;
            return temp;
        }
        int lsum=sum(root->left);
        int rsum=sum(root->right);
        int temp=root->data;
        root->data=lsum+rsum;
        return root->data+temp;
    }
    
    void toSumTree(Node *root)
    {
        sum(root);
    }
};