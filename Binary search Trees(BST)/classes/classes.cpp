#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int val) {
    // It is the first node
    if(root == NULL) {
        root = new Node(val);
        return root;
    }
    // It is not the first node
    if(val > root->data) {
        root->right = insertIntoBST(root->right, val);
    } else {
        root->left = insertIntoBST(root->left, val);
    }
    return root;
}

void createBST(Node* &root) {
    int val;
    cout << "Enter value:" << endl;
    cin >> val;
    while(val != -1) {
        root = insertIntoBST(root, val);
        cout << "Enter value:" << endl;    
        cin >> val;
    }
}

void levelOrderTraversal(Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if(temp->left != NULL) {
                q.push(temp->left);
            }
            if(temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

void preorder(Node* root){
    //NLR
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    //LNR
    //Inorder will come sorted in case of BST
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    //LRN
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

Node* minValue(Node* root){
    if(root==NULL){
        cout<<"No min value available";
        return nullptr;
    }
    Node* temp = root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    if(root==NULL){
        cout<<"No min value available";
        return nullptr;
    }
    Node* temp = root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

bool searchInBST(Node* root, int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true; 
    }
    bool leftAns=false;
    bool rightAns=false;
    if(target>root->data){
        rightAns = searchInBST(root->right, target);
    }else{
        leftAns = searchInBST(root->left, target);
    }
    return leftAns || rightAns;
}

Node* deleteFromBST(Node* root, int target){
    //Target ko dhundo
    if(root==NULL)
    return NULL;
    //Target Ko Delete Karo
    if(root->data==target){
        //now we will do deletion
        //4 cases

        //1st cases of leaf node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //2nd case of left non null and right null
        else if(root->left!=NULL && root->right==NULL){
            Node* child = root->left;
            delete root;
            return child;
        }

        //3rd case of right non null and left null
        else if(root->left==NULL && root->right!=NULL){
            Node* child = root->right;
            delete root;
            return child;
        }

        //Last case of both non null
        else{
            //a->left Sub Tree Max VAlue Lao
            Node* maxL = maxValue(root->left);
            //replacement
            root->data=maxL->data;

            //delete actual maxL vali node
            root->left=deleteFromBST(root->left, maxL->data);
        }
    }
    else if(root->data>target){
        //Go left
        root->left = deleteFromBST(root->left, target);
    }else{
        //Go right
        root->right = deleteFromBST(root->right, target);
    }
    return root;
}

int main() {
    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    Node* min = minValue(root);
    if(min==nullptr)
    cout<<"No minimum value available"<<endl;
    else
    cout<<"The minimum value is"<<min->data<<endl;
    Node* max = maxValue(root);
    if(max==nullptr)
    cout<<"No minimum value available"<<endl;
    else
    cout<<"The minimum value is"<<max->data<<endl;

    int target;
    cout<<"Enter the value to be searched in the array";
    cin>>target;
    if(searchInBST(root, target)){
        cout<<"Element Found"<<endl;
    }else{
        cout<<"ELment not found"<<endl;
    }  
}

// 50 30 20 25 40 60 70 80 55