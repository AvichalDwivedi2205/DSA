#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<tuple<int, int, int>> q; 
        q.push({0, src, k + 1}); 
        
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]}); 
        }
        vector<int> price(n, 1e9);
        price[src] = 0;

        while (!q.empty()) {
            auto [cost, city, stops] = q.front();
            q.pop();

            if (stops == 0) continue;
            for (auto [next_city, next_cost] : adj[city]) {
                if (cost + next_cost < price[next_city]) {
                    price[next_city] = cost + next_cost;
                    q.push({price[next_city], next_city, stops - 1});
                }
            }
        }

        return (price[dst] == 1e9) ? -1 : price[dst];
    }
};
