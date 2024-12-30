# include <stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // If we sort the deck then we will get the simulated output
        // After that we can proceed
        sort(deck.begin(), deck.end());
        queue<int> q;
        vector<int> ans(deck.size(), 0);
        //Filling the indexes into the queue
        for(int i=0;i<deck.size();i++){
            q.push(i);
        }
        //Reverse Simulation Means filling back using the sorted deck
        for(int i=0;i<deck.size();i++){
            // 1.) Reveal
            ans[q.front()]=deck[i];
            q.pop();

            // Push to the back and pop
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};