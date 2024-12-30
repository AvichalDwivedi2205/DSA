# include <vector>
# include <queue>
using namespace std;

class Solution {
public:

    int AvichalOp(int n, int k){
       vector<int> circle;
        for (int i = 1; i <= n; ++i) {
            circle.push_back(i);
        }
        int cur_ind = 0;

        while (circle.size() > 1) {
            int next_to_remove = (cur_ind + k - 1) % circle.size();
            circle.erase(circle.begin() + next_to_remove);
            cur_ind = next_to_remove;
        }

        return circle[0];
    }

    int findTheWinner(int n, int k) {
        return AvichalOp(n,k);
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i+1);
        }
        while(q.size()!=1){
            int i=k;
            for(int j=1;j<i;j++){
                int a=q.front();
                q.pop();
                q.push(a);
            }
            q.pop();
        }
        return q.front();
    }
};