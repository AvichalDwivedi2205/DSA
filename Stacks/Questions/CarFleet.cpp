# include<iostream>
# include<stack>
# include<vector>
# include<algorithm>
using namespace std;

class Solution {
    class Car{
        public:
        int pos, speed;
        Car(int p, int s):pos(p), speed(s){};
    };
public:

    static bool mycomp(Car &a, Car &b){
        return a.pos<b.pos;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // One approach is looping but it will have O(n^2) or even more time complexity
        vector <Car> cars;
        for(int i=0; i<position.size(); i++){
            Car car(position[i], speed[i]); 
            cars.push_back(car);
        }
        sort(cars.begin(), cars.end(), mycomp);
        stack <float> st;
        for(auto car:cars){
            float time = (target-car.pos)/((float)car.speed);
            while(!st.empty() && time>=st.top()){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};