class Solution {
public:
    int mySqrt(int x) {
        long long s=0,e=x,mid=(s+e)/2;
        int ans=-1;
        while(e>=s){
            if(mid*mid == x){
                ans=mid;
                break;
            }else if(mid*mid > x){
                e=mid-1;
            }else{
                ans=mid;
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;

    }
};