# include <iostream>
# include <map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:

     Node* helper(Node* head, unordered_map<Node*, Node*>&mp){
        if(head==0) return 0;
        Node* newHead = new Node(head->val);
        mp[head]=newHead;
        newHead->next=helper(head->next, mp);
        if(head->random){
            newHead->random=mp[head->random];
        }
        return newHead;
     }

     Node* helperO1(Node* head){
        if(head==NULL) return NULL;
        Node* it=head;
        while(it){
            Node* cloneNode = new Node(it->val);
            cloneNode->next=it->next;
            it->next=cloneNode;
            it=it->next->next;
        }

        it=head;
        while(it){
            Node* cloneNode = it->next;
            cloneNode->random=it->random? it->random->next:nullptr;
            it=it->next->next;
        }

        it=head;
        Node* cloneHead=it->next;
        while(it){
            Node* temp=it->next;
            it->next=it->next->next;
            if(temp->next){
                temp->next=temp->next->next;
            }
            it=it->next;
        }
        return cloneHead;
     }

    Node* copyRandomList(Node* head) {
        return helperO1(head);
    }
};