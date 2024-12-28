# include<iostream>
# include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
    }

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) { // Fixed condition
            span += st.top().second;
            st.pop();
        }
        st.push({price, span}); // Corrected to push a pair
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
