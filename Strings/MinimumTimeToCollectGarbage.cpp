#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickTime=0;
        int lastP=0,lastM=0,lastG=0;
        int travelP=0, travelM=0, travelG=0;
        for(int i=0;i<garbage.size();i++){
            string temp = garbage[i];
            for(int j=0;j<temp.size();j++){
                char ch=temp[j];
                if(ch=='M'){
                    pickTime++;
                    lastM=i;
                }
                if(ch=='P'){
                    pickTime++;
                    lastP=i;
                }
                if(ch=='G'){
                    pickTime++;
                    lastG=i;
                }
            }
        }
        for(int i=0;i<lastM;i++){
                travelM+=travel[i];
        }
        for(int i=0;i<lastP;i++){
            travelP+=travel[i];
        }
        for(int i=0;i<lastG;i++){
            travelG+=travel[i];
        }
        return pickTime + travelP +travelM +travelG;
    }
};