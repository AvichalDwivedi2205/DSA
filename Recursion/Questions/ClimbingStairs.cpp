class Solution {
public:
    int climbStairsrecursion(int n) {
        if(n==1)
        return 1;
        if(n==2)
        return 2;
        int ans = climbStairsrecursion(n-1)+climbStairsrecursion(n-2);
        return ans;
    }

     int climbStairsloop(int n) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int prev=1;
        int curr=2;
        for(int i=2;i<n;i++){
            int temp=prev+curr;
            prev=curr;
            curr=temp;
        }
        return curr;
    }
};