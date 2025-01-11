# include <iostream>
# include <queue>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops=0;
        int distance=0;
        int i=0;
        int fuel=startFuel;
        priority_queue<pair<int, int>>pq; // Stores fuel, position
        while(true){
            while(i<stations.size()){
                // Push stations within the reach with my current fuel levels from my positions
                if(stations[i][0]<=distance+fuel){
                    pq.push({stations[i][1], stations[i][0]});
                }else{
                    break;
                }
                ++i;              
            }

            //Travel with full fuel level
            distance+=fuel;
            fuel=0;

            //reached
            if(distance>=target) break;

            //no fuel station within reach
            if(pq.empty()){
                stops=-1;
                break;
            }

            //refuel and readjust distance and fuel based on the distance travelled and fuel used till that station
            auto &top=pq.top();
            fuel=distance-top.second+top.first;
            distance=top.second;
            pq.pop();
            stops++;
        }
        return stops;
    }
};