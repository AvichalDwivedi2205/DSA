#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val):data(val), left(NULL), right(NULL) {};
};

class Solution{
    public:
    
    Node* insert(Node* root, int val, int &succ){
        if(!root) return new Node(val);
        if(val>=root->data){
            root->right=insert(root->right, val, succ);
        }else{
            succ=root->data;
            root->left=insert(root->left, val, succ);
        }
        return root;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(arr.size(), -1);
        Node* root=NULL;
        for(int i=arr.size()-1;i>=0;i--){
            int succ=-1;
            root=insert(root, arr[i], succ);
            ans[i]=succ;
        }
        return ans;
    }
};