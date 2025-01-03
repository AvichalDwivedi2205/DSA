struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to find the middle element and split the list
    ListNode* middleEle(ListNode* head, ListNode* &prev) {
        ListNode* slow = head;
        ListNode* fast = head;
        prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // If prev is not null, disconnect the left part of the list
        if (prev) {
            prev->next = nullptr;
        }
        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr; // Base case for an empty list
        if (!head->next) return new TreeNode(head->val); // Base case for a single node

        ListNode* prev = nullptr;
        ListNode* middle = middleEle(head, prev);

        // Create the root of the BST
        TreeNode* root = new TreeNode(middle->val);

        // Recursive calls for left and right subtrees
        root->left = sortedListToBST(head);     // Left part of the list
        root->right = sortedListToBST(middle->next); // Right part of the list

        return root;
    }
};
