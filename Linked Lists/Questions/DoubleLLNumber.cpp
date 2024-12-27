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

    void recursion(ListNode* head, int &carry){
        if(head==NULL) return;
        recursion(head->next, carry);
        int value=(head->val)*2 + carry;
        head->val=value%10;
        carry=value/10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry=0;
        recursion(head, carry);
        if(carry){
            ListNode* newHead = new ListNode(carry);
            newHead->next=head;
            head=newHead;
        }
        return head;
    }
};