# include <iostream>
# include <queue>
using namespace std;

struct Node {
int data;
Node *left;
Node *right;

Node(int val) {
    data = val;
    left = right = NULL;
}
};

class Solution {
  public:
  
    int nodeCount(struct Node* root){
        if(root==NULL) return 0;
        int l=nodeCount(root->left);
        int r=nodeCount(root->right);
        return 1+l+r;
    }
    
    bool isCBTM2(struct Node* root, int i, int &n){
        if(root==NULL) return true;
        if(i>n) return false;
        return isCBTM2(root->left, 2*i, n) && isCBTM2(root->right, 2*i+1, n);
    }
    
    bool isMax(struct Node* root){
        if(root==NULL) return true;
        bool l=isMax(root->left);
        bool r=isMax(root->right);
        bool ans=false;
        if(root->left==NULL && root->right==NULL) ans=true;
        else if(root->left!=NULL && root->right==NULL) 
        ans=root->data>root->left->data;
        else{
            ans=root->data>root->left->data && root->data>root->right->data;
        }
        return ans && l && r;
    }
  
    bool isCBTM1(struct Node* tree){
        queue<Node*> q;
        if(tree==NULL) return true;
        q.push(tree);
        int flag=0;
        while(!q.empty()){
            struct Node* ele=q.front();
            q.pop();
            if(ele->left){
                if(flag) return false;
                else q.push(ele->left);
            }else{
                flag=1;
            }
            if(ele->right){
                if(flag) return false;
                else q.push(ele->right);
            }else{
                flag=1;
            }
        }
        return true;
    }
  
    bool isHeap(struct Node* tree) {
        // code here
        //Method 1
        // return isCBTM1(tree) && isMax(tree);
        
        //Method 2
        int n=nodeCount(tree);
        int i=1;
        return isCBTM2(tree,i,n) && isMax(tree);
    }
};