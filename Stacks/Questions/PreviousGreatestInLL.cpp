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
    vector<int> prevLargerNodes(ListNode* head) {
        stack<int> st;  // Stack to hold the elements as we traverse the list
        vector<int> result;
        ListNode* temp = head;

        while (temp != nullptr) {
            int curr = temp->val;
            
            // Pop elements from the stack that are less than or equal to the current value
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }
            
            if (st.empty()) {
                result.push_back(0);  // No larger element found, so push 0
            } else {
                result.push_back(st.top());  // The previous greater element
            }
            
            st.push(curr);  // Push current element to the stack
            temp = temp->next;
        }

        return result;
    }
};
