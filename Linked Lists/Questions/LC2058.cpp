# include<iostream>
# include <vector>
using namespace std;
//Another way to reduce a vector would be to store the first cirtical point and the last and in between keep another variable for previous critical point.
//the answer would be min(index-prevcriticalpoint) and the max will be index-firstcirticalpoint at the end of the loop
//Also keep a variavle for amount of critical points if less than 2 just return [-1,-1] 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector <int> v;
        vector <int> ans;
        ListNode* prev=head;
        ListNode* curr=head->next;
        int index=1;
        while(curr->next!=NULL){
            int currval=curr->val;
            int nextval=curr->next->val;
            int prevval=prev->val;
            if(currval>prevval && currval>nextval){
                v.push_back(index);
            }
            if(currval<prevval && currval<nextval){
                v.push_back(index);
            }
            index++;
            prev=curr;
            curr=curr->next;
        }
        if(v.size()<2){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }else{
            int minDistance = INT_MAX;
            for (size_t i = 1; i < v.size(); ++i) {
                minDistance = min(minDistance, v[i] - v[i - 1]);
            }
            
            int maxDistance = v.back() - v.front();
            ans.push_back(minDistance);
            ans.push_back(maxDistance);
            
            return ans;
        }
    }
};