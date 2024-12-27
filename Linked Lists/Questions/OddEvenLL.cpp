# include<iostream>
# include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LEETCODE 328

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // Handle edge cases

        ListNode* odd = head; // Pointer to traverse odd nodes
        ListNode* even = head->next; // Pointer to traverse even nodes
        ListNode* evenHead = even; // Save the head of the even nodes

        while (even && even->next) {
            odd->next = even->next; // Connect the next odd node
            odd = odd->next; // Move the odd pointer
            even->next = odd->next; // Connect the next even node
            even = even->next; // Move the even pointer
        }

        odd->next = evenHead; // Connect odd list to even list
        return head; // Return the modified head
    }
};
