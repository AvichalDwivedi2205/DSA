# include<iostream>
# include <stack>
# include <vector>
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

    ListNode* reverse(ListNode* head) {
        if (!head) return nullptr;  // Add a check for an empty list
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }


    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> result;
        ListNode* temp = reverse(head);

        while (temp != nullptr) {
            int curr = temp->val;
            
            // Pop elements from the stack that are less than or equal to the current value
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }
            
            if (st.empty()) {
                result.push_back(0);  // No larger element, so push 0
            } else {
                result.push_back(st.top());  // Next larger element
            }
            
            st.push(curr);  // Push current element to the stack
            temp = temp->next;
        }

        // Reverse the result vector to match the original order
        ::reverse(result.begin(), result.end());
        return result;
    }

};