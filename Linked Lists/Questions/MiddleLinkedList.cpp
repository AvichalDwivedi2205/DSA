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

    ListNode* LeftmiddleNode(ListNode* head) {
        ListNode* temp=head;
        ListNode* middle=head;
        while(temp->next!=NULL && (temp->next)->next!=NULL){
            middle=middle->next;
            temp=(temp->next)->next;
        }
        return middle;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        ListNode* middle=head;
        while(temp!=NULL && temp->next!=NULL){
            middle=middle->next;
            temp=(temp->next)->next;
        }
        return middle;
    }
};