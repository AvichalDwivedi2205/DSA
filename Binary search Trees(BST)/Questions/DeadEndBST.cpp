#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
  public:
  
    void fun(Node* root, map<int, bool> &visited, bool &ans){
        if(root==NULL)
        return;
        visited[root->data]=true;
        if(root->left==NULL && root->right==NULL){
            //Check Dead end
            int xp1=root->data+1;
            int xm1=root->data-1==0?root->data:root->data-1;
            if(visited.find(xp1)!=visited.end() && visited.find(xm1)!=visited.end()){
                ans=true;
                return;
            }
        }
        fun(root->left, visited, ans);
        fun(root->right, visited, ans);
    }
  
    bool isDeadEnd(Node *root)
    {
        //Your code here
        bool ans = false;
        map<int, bool> visited;
        fun(root, visited, ans);
        return ans;
    }
};