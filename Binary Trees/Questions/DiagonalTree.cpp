struct Node
{
    int data;
    Node* left, * right;
}; 

#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
  
    void createMapping(Node* root,  map<int, vector<int>> &mp, int index){
        if(root==NULL)
        return;
        mp[index].push_back(root->data);
        createMapping(root->left, mp, index+1);
        createMapping(root->right, mp, index);
    }
  
    vector<int> diagonal(Node *root) {
        // code here
        map<int, vector<int>> mp;
        vector<int> ans;
        createMapping(root, mp, 0);
        for(auto v:mp){
            for(int j=0;j<v.second.size();j++){
                ans.push_back(v.second[j]);
            }
        }
        return ans;
    }
};

class Solution2 {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL)
        return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            while(temp!=NULL){
                ans.push_back(temp->data);
                if(temp->left)
                q.push(temp->left);
                temp=temp->right;
            }
        }
        return ans;
    }
};