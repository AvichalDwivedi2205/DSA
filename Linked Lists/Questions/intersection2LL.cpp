# include<map>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while(a->next && b->next){
            if(a==b)
            return a;
            a=a->next;
            b=b->next;
        }
        if(a->next==NULL){
            int length=0;
            while(b->next){
                length++;
                b=b->next;
            }
            while(length--){
                headB=headB->next;
            }
        }else{
            int length=0;
            while(a->next){
                length++;
                a=a->next;
            }
            while(length--){
                headA=headA->next;
            }
        }

        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};