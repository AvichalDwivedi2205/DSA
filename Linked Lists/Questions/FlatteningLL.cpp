# include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

class Solution {
public:

    Node* merge(Node* a, Node* b){
        if(!a) return b;
        if(!b) return a;
        
        Node* ans = NULL;
        if(a->data < b->data){
            ans=a;
            a->bottom=merge(a->bottom,b);
        }else{
            ans=b;
            b->bottom=merge(a,b->bottom);
        }
        return ans;
    }

    Node *flatten(Node *root)
    {
        if(root->next==NULL) return root;
        return merge(root, flatten(root->next));
    }
};