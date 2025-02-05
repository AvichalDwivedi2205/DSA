# include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    //Recursive Approach
    ListNode* reverseRecursionList(ListNode* prev, ListNode* curr){
        if(curr==NULL){
            return prev;
        }
        ListNode* nextNode=curr->next;
        curr->next=prev;
        return reverseRecursionList(curr, nextNode);
    }
    //Iterative Approach
    ListNode* reverseList(ListNode* head) {
        ListNode* currNode = head;
        ListNode* prevNode=NULL;
        while(currNode!=NULL){
            ListNode* nextNode=currNode->next;
            currNode->next=prevNode;
            prevNode=currNode;
            currNode=nextNode;
        }
        return prevNode; 
    }
};