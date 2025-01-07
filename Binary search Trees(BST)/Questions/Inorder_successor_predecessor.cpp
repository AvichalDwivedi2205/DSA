#include <iostream>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        
        // Inorder Successor
        Node* temp=root;
        while(temp){
            if(temp->key>key){
                suc=temp;
                temp=temp->left;
            }else{
                temp=temp->right;
            }
        }
        
        //Inorder Predessecor
        temp=root;
        while(temp){
            if(temp->key<key){
                pre=temp;
                temp=temp->right;
            }else{
                temp=temp->left;
            }
        }
        
    }
};