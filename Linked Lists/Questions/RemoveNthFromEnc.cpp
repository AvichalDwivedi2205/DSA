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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL){
            temp=temp->next;
            c++;
        }
        temp=head;
        n=c-n+1;
        ListNode* curr=head;
        ListNode* prev=NULL;
        if(n<1){
            return head;
        }else if(n==1){
            head=head->next;
            delete curr;
            return head;
        }else{
            for(int i=0;i<n-1;i++){
                prev=curr;
                curr=curr->next;
            }
            prev->next=curr->next;
            delete curr;
        }
        return head;
    }
};