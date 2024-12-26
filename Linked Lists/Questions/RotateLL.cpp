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

    int length(ListNode* head){
        int length=0;
        ListNode* temp=head;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0) return head;
        int len=length(head);
        if(len==0 || len==1) return head;
        int shift=k%len;
        int left=len-shift;
        if(shift==0){
            return head;
        }
        ListNode* newHead=head;
        ListNode* last=NULL;
        while(left--){
            last=newHead;
            newHead=newHead->next;
        }
        last->next=NULL;
        ListNode* temp=newHead;
        shift--;
        while(shift--){
            temp=temp->next;
        }
        temp->next=head;
        return newHead;
    }
};