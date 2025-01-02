# include<iostream>
# include<vector>
# include<map>
# include<queue>
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
  
    Node* makeNodeToParentMappingAndFindTargetNode(Node* root, int target, unordered_map <Node*, Node*> &pmap){
        queue<Node*> q;
        Node* targetNode=NULL;
        pmap[root]=NULL;
        q.push(root);
        while(!q.empty()){
            Node* front = q.front(); q.pop();
            if(front->data==target){
                targetNode=front;
            }
            if(front->left){
                q.push(front->left);
                pmap[front->left]=front;
            }
            if(front->right){
                q.push(front->right);
                pmap[front->right]=front;
            }
        }
        return targetNode;
    }
    
    int burnTheTree(Node* targetNode, unordered_map <Node*, Node*> &pmap){
        unordered_map <Node*, bool> isBurnt;
        int T=0;
        queue<Node*>q;
        q.push(targetNode);
        isBurnt[targetNode]=true;
        while(!q.empty()){
            int size=q.size();
            bool isFireSpreaded=false;
            for(int i=0;i<size;i++){
                Node* front = q.front();
                q.pop();
                if(front->left && !isBurnt[front->left]){
                    q.push(front->left);
                    isBurnt[front->left]=true;
                    isFireSpreaded=true;
                }if(front->right && !isBurnt[front->right]){
                    q.push(front->right);
                    isBurnt[front->right]=true;
                    isFireSpreaded=true;
                }if(pmap[front] && !isBurnt[pmap[front]]){
                    q.push(pmap[front]);
                    isBurnt[pmap[front]]=true;
                    isFireSpreaded=true;
                }
            }
            if(isFireSpreaded) T++;
        }
        return T;
    }
  
    int minTime(Node* root, int target) {
        // code here
        //Steps
        //Find the node
        //Make node to parent node mapping
        unordered_map <Node*, Node*> pmap;
        Node* targetNode = makeNodeToParentMappingAndFindTargetNode(root, target, pmap);
        return burnTheTree(targetNode, pmap);
    }
};