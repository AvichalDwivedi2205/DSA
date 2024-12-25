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

     ListNode* reverseRecursionList(ListNode* prev, ListNode* curr){
        if(curr==NULL){
            return prev;
        }
        ListNode* nextNode=curr->next;
        curr->next=prev;
        return reverseRecursionList(curr, nextNode);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        ListNode* middle=head;
        while(temp->next!=NULL && (temp->next)->next!=NULL){
            middle=middle->next;
            temp=(temp->next)->next;
        }
        return middle;
    }

    bool compareList(ListNode* head1, ListNode* head2){
        ListNode* temp1=head1;
        ListNode* temp2=head2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val!=temp2->val)
            return false;
            else{
                temp1=temp1->next;
                temp2=temp2->next; 
            }  
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* midNode = middleNode(head);
        ListNode* head2=midNode->next;
        midNode->next=NULL;
        ListNode* prev=NULL;
        head2=reverseRecursionList(prev, head2);
        return compareList(head,head2);
    }
};