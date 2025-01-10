# include <iostream>
# include <queue>
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

    class Compare{
        public:
        bool operator()(ListNode*a , ListNode* b){
            return a->val>b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // We can think of using heap here because heap gives us the minimum value in a particular array in minimum time complexity
        // So we can think of applying heap here
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
         for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        if(pq.empty()) return NULL;
        auto ele=pq.top();
        ListNode* head=new ListNode(ele->val);
        pq.pop();
        if(ele->next!=NULL){
            ele=ele->next;
            pq.push(ele);
        }
        ListNode* temp = head;
        while(!pq.empty()){
            auto element = pq.top();
            pq.pop();
            ListNode* newTemp = new ListNode(element->val);
            temp->next=newTemp;
            temp = temp->next;
            if(element->next!=NULL){
                element=element->next;
                pq.push(element);
            }
        }
        return head;
    }
};