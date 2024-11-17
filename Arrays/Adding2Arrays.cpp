#include <string>
using namespace std;
#include <vector>

string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
        // Complete the function
        int i=arr1.size()-1,j=arr2.size()-1,carry=0, sum=0;
        string ans = "";
        while(i>=0 && j>=0){
            sum = arr1[i]+arr2[j]+carry;
            carry=sum/10;
            sum=sum%10;
            ans=to_string(sum)+ans;
            i--;
            j--;
            sum=0;
        }
        while(i>=0){
            int sex=carry+arr1[i];
            carry=sex/10;
            sex=sex%10;
            ans=to_string(sex)+ans;
            i--;
        }
        while(j>=0){
            int sex=carry+arr2[j];
            carry=sex/10;
            sex=sex%10;
            ans=to_string(sex)+ans;
            j--;
        }
        if(carry>0){
            ans=to_string(carry)+ans;
        }
        return ans;
    }