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

    ListNode* findMid(ListNode* head) {
        ListNode* temp=head;
        ListNode* middle=head;
        while(temp->next!=NULL && (temp->next)->next!=NULL){
            middle=middle->next;
            temp=(temp->next)->next;
        }
        return middle;
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2 == NULL) return list1;
    
        ListNode* ans = new ListNode(-1);
        ListNode*ptr=ans;
        while(list1&&list2){
            if((list1->val)>list2->val){
                ptr->next=list2;
                ptr=list2;
                list2=list2->next;
            }else{
                ptr->next=list1;
                ptr=list1;
                list1=list1->next;
            }
        }
        if(list1)
        ptr->next=list1;
        if(list2)
        ptr->next=list2;
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        // Break LL using 2 halves using middle of LL
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next=NULL;

        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }
};