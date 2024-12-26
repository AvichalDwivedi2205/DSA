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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
};