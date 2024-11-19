#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int divide(int divident, int divide) {
        if (divident == INT_MIN && divide == -1) return INT_MAX;
        if (divident == INT_MIN && divide == 1) return INT_MIN;
        long long divisor=abs(divide);
        long long dividend=abs(divident);
        long long s=0, e=dividend, mid=s+(e-s)/2;
        long long ans=-1;
        while(e>=s){
            if(mid*divisor==dividend){
                ans=mid;
                break;
            }
            else if(mid*divisor<dividend){
                ans=mid;
                s=mid+1;
            }
            else
            e=mid-1;
            mid=s+(e-s)/2;
        }
        if((divident>0 && divide>0) || (divident<0 && divide<0))
        return ans;
        else{
            ans=ans*-1;
            return ans;
        }
    }
};