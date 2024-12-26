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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = new ListNode(-1);
        ListNode* temp=head->next;
        ListNode* tempNew = newHead;
        int value=0;
        while(temp!=NULL){
            if(temp->val==0){
                ListNode* newNode = new ListNode(value);
                tempNew->next=newNode;
                tempNew=newNode;
                temp=temp->next;
                value=0;
            }else{
                value=value+(temp->val);
                temp=temp->next;
            }
        }
        tempNew->next=NULL;
        return newHead->next;
    }
};