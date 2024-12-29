# include <iostream>
# include <queue>
# include <vector>
using namespace std;

class Solution {
public:

    //CHUMMA SOLUTION I JUST LOVE IT.
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;  // Total gas available
        int totalCost = 0; // Total gas cost
        int currentGas = 0; // Current gas in the tank
        int startIndex = 0; // Candidate starting station index

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];
            
            // If we can't proceed to the next station
            if (currentGas < 0) {
                startIndex = i + 1; // Start from the next station
                currentGas = 0;    // Reset current gas
            }
        }

        // Check if the total gas is sufficient for the total cost
        return totalGas >= totalCost ? startIndex : -1;
    }
};
