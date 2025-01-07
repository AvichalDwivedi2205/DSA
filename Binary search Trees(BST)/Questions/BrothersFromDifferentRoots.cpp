#include <iostream>
#include <stack>
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

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        // BRute force would be to find go for each element in the left tree
        // Aftre that you subtract the difference and search for that element in the ight tree
        //If you get then then return true 
        //If there is no such pair then return false
        
        //Better method would be to do inorder traversal of left and right BST
        // Then we use the 2 pointer approach to traverse through the entire array
        
        // Last method would be inorder traversal using stack. This is the best method
        // Here no space complexity would be needed
        
        int ans=0;
        stack <Node*> st1;
        stack <Node*> st2;
        Node* a = root1;
        Node* b = root2;
        while(1){
            while(a){
                // Inorder Traversal
                st1.push(a);
                a=a->left;
            }
            while(b){
                // Reverse Inorder Traversal
                st2.push(b);
                b=b->right;
            }
            if(st1.empty() || st2.empty()){
                break;
            }
            auto atop=st1.top();
            auto btop=st2.top();
            
            int sum = atop->data+btop->data;
            if(sum==x){
                ans++;
                st1.pop();
                st2.pop();
                a=atop->right;
                b=btop->left;
            }else if(sum<x){
                st1.pop();
                a=atop->right;
            }else{
                st2.pop();
                b=btop->left;
            }
        }
        return ans;
    }
};