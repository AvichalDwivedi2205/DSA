# include <iostream>
# include <queue>
using namespace std;

class Node{
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

int getKthSmallestElement(int arr[], int k, int size){
    priority_queue<int> pq;
    // process the first k elements
    for(int i=0;i<k;i++)
    pq.push(arr[i]);
    for(int i=k;i<size;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int getKthGrestestElement(int arr[], int k, int size){
    priority_queue<int, vector<int>, greater<int>> pq;
    // process the first k elements
    for(int i=0;i<k;i++)
    pq.push(arr[i]);
    for(int i=k;i<size;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

class info{
    public:
     int maxVal;
     bool isHeap;
     info(){

     }
     info(int a, bool b){
        this->maxVal=a;
        this->isHeap=b;
     }
};

info checkMaxHeap(Node* root){
    if(root==NULL){
        info temp;
        temp.maxVal=INT_MIN;
        temp.isHeap=true;
        return temp;
    }
    if(root->left==NULL && root->right==NULL){
        info temp;
        temp.maxVal=root->data;
        temp.isHeap=true;
        return temp;
    }
    info leftAns = checkMaxHeap(root->left);
    info rightAns = checkMaxHeap(root->right);
    // 1 case solve
    if(root->data>leftAns.maxVal && root->data>rightAns.maxVal && leftAns.isHeap && rightAns.isHeap){
        info ans;
        ans.maxVal=root->data;
        ans.isHeap=true;
        return ans;
    }else{
        info ans;
        ans.maxVal=max(root->data, max(leftAns.maxVal, rightAns.maxVal));
        ans.isHeap=false;
        return ans;
    }
}

void inorder(Node* root, vector<int> &in){
    if(root==NULL) return;
    //LNR
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void levelOrder(Node* root, vector<int> in){
    queue<Node*> q;
    if(root==NULL) return;
    q.push(root);
    int i=in.size()-1;
    while(!q.empty()){
        auto ele=q.front();
        ele->data=in[i--];
        if(ele->left)
        q.push(ele->left);
        if(ele->right)
        q.push(ele->right);
    }
}

void postorder(Node* root, vector<int> &in, int &i){
    if(root==NULL) return;
    //LRN
    postorder(root->left, in, i);
    postorder(root->right, in, i);
    root->data=in[i];
}

void BSTToMaxHeap(Node* root){
    vector<int> in;
    inorder(root, in);
    //We can do it by 2 methods 
    //Method 1 is by level order and replacing all the elments by the inorder
    levelOrder(root, in);
    // Another Method is by postorder that is replacing all the elements by inorder in post order traversal
    // postorder(root, in)
}

int main(){
    int arr[] = {9,10,11,12,1,2,3,4,5,6};
    int size=10;
    int k=1;
    int ans = getKthSmallestElement(arr, k, size);
    cout<<k<<"th smallest element is "<<ans<<endl;
    ans = getKthGrestestElement(arr, k, size);
    cout<<k<<"th grestest element is "<<ans<<endl;
    return 0;
}