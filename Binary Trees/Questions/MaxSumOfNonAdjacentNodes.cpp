# include<iostream>
# include<vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    
    pair<int, int> sum(Node* root){
        if (root==NULL){
            return {0, 0};
        }
        auto ls = sum(root->left);
        auto rs = sum(root->right);
        // If we are including the current element;
        int suminc=root->data+ls.second+rs.second;
        // sum excluding the current element
        int sumexc = max(ls.first, ls.second) + max(rs.second, rs.first);
        
        return {suminc, sumexc};
    }
    
    int getMaxSum(Node *root) 
    {
        // Add your code here
        auto ans = sum(root);
        return max(ans.first, ans.second);
    }
};