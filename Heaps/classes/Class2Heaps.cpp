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