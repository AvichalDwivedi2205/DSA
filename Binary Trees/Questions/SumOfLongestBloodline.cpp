# include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    pair<int, int> MaxSum(Node* root) {
        if (root == NULL) 
            return {0, 0}; // Base case: zero length, zero sum

        // Recursively calculate for left and right subtrees
        auto left = MaxSum(root->left);
        auto right = MaxSum(root->right);

        // Initialize current path's sum
        int currentSum = root->data;

        // Determine the longer path (or path with higher sum if lengths are equal)
        if (left.first == right.first) {
            currentSum += max(left.second, right.second);
        } else if (left.first > right.first) {
            currentSum += left.second;
        } else {
            currentSum += right.second;
        }

        // Return updated path length and sum
        return {max(left.first, right.first) + 1, currentSum};
    }

    int sumOfLongRootToLeafPath(Node* root) {
        auto result = MaxSum(root);
        return result.second; // Return the maximum sum
    }
};
