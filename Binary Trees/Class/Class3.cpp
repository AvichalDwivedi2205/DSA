# include <iostream>
# include <vector>
# include <queue>
#include<map>
using namespace std;

class Node{
    public:
      int data;
      Node* left;
      Node* right;

      Node(int val){
        data=val;
        left=NULL;
        right=NULL;
      }
};

Node* createTree(){
    cout<<"Enter the value of Node:"<<endl;
    int value;
    cin>>value;

    if(value==-1){
        return NULL;
    }
    Node* root = new Node(value);
    cout<<"Entering left Node value"<<endl;;
    root->left=createTree();
    cout<<"Entering right node value"<<endl;;
    root->right=createTree();
    return root;
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void LevelOrder(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	//asli traversal start krete h 

	while(!q.empty()) {
		Node* front = q.front();
		q.pop();

		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			//valid node wala case
			cout << front->data << " ";

			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
	}
}

void printLeftView(Node* root, int level, vector<int>& leftView){
    if(root==NULL){
        return;
    }
    if(level==leftView.size()){
        leftView.push_back(root->data);
    }
    printLeftView(root->left, level+1, leftView);
    printLeftView(root->right, level+1, leftView);
}

void printrightView(Node* root, int level, vector<int> &rightView){
        if(root==NULL){
        return;
        }
        if(level==rightView.size()){
            rightView.push_back(root->data);
        }
        printrightView(root->right, level+1, rightView);
        printrightView(root->left, level+1, rightView);
    }

void TopView(Node* root){
    map <int, int> mp;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node* ,int> temp=q.front();
        q.pop();

        Node* front = temp.first;
        int hd = temp.second;//hd->horiozntal distance
        //If the answer has not been stored for this horizontal distance then store in inside of the map
        if(mp.find(hd) == mp.end()){
            mp[hd]=front->data;
        }
        // child insert karna hai ab
        if(front->left!=NULL)
        q.push(make_pair(front->left, hd-1));
        if(front->right!=NULL)
        q.push(make_pair(front->right, hd+1));
    }
    cout<<endl;
    cout<<"Printing Top View"<<endl;
    for(auto i:mp){
        cout<<i.second<<" ";
    }
}

void BottomView(Node* root){
    map <int, int> mp;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node* ,int> temp=q.front();
        q.pop();

        Node* front = temp.first;
        int hd = temp.second;//hd->horiozntal distance
        //Here we will just update it so that the last value at that horizontal distance will be stored in the map
        mp[hd]=front->data;
        // child insert karna hai ab
        if(front->left!=NULL)
        q.push(make_pair(front->left, hd-1));
        if(front->right!=NULL)
        q.push(make_pair(front->right, hd+1));
    }
    cout<<endl;
    cout<<"Printing Top View"<<endl;
    for(auto i:mp){
        cout<<i.second<<" ";
    }
}


void printLeftBoundary(Node* root) {
	if(root == NULL) {
		return;
	}
	if(root->left == NULL && root->right == NULL) {
		return;
	}
	cout << root->data << " ";
	if(root->left != NULL) {
		printLeftBoundary(root->left);
	}
	else {
		printLeftBoundary(root->right);
	}
}

void printRightBoundary(Node* root) {
	if(root == NULL) {
		return;
	}
	if(root->left == NULL && root->right == NULL) {
		return;
	}
	
	if(root->right != NULL) {
			printRightBoundary(root->right);
	}
	else {
			printRightBoundary(root->left);
	}
	cout << root->data << " ";
}

void printLeafBoundary(Node* root) {
	if(root == NULL )
		return;

	if(root->left == NULL && root->right == NULL) {
		cout << root->data <<" ";
	}
	printLeafBoundary(root->left);
	printLeafBoundary(root->right);
}


void boundaryTraversal(Node* root ) {
	if(root == NULL)
		return;
	cout << root->data << " ";
	printLeftBoundary(root->left);
	printLeafBoundary(root->left);
	printLeafBoundary(root->right);
	printRightBoundary(root->right);
}

int main(){
    Node* root=createTree();
    vector <int> leftView;
    vector <int> rightView;
    cout<<"PreOrder Traversal"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"PostOrder Traversal"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"InOrder Traversal"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Level Traversal"<<endl;
    LevelOrder(root);
    cout<<"Printing left View"<<endl;
    printLeftView(root, 0, leftView);
    for(int i=0;i<leftView.size();i++){
        cout<<leftView[i]<<" ";
    }
    cout<<endl;
    cout<<"Printing right View"<<endl;
    printrightView(root, 0, rightView);
    for(int i=0;i<rightView.size();i++){
        cout<<rightView[i]<<" ";
    }
    TopView(root);
    BottomView(root);
    cout<<endl;
    cout<<"Boundary Traversal"<<endl;
    boundaryTraversal(root);
}

