# include <iostream>
# include <vector>
using namespace std;

class Solution{
    public:
    
    void heapify(vector<int> &v, int i, int size){
        while(true){
            int left=2*i+1;
            int right=2*i+2;
            int swapIndex=i;
            if(left<size && v[left]>v[swapIndex]){
                swapIndex=left;
            }
            if(right<size && v[right]<v[swapIndex]){
                swapIndex=right;
            }
            if(swapIndex==i) break;
            swap(v[i], v[swapIndex]);
            i=swapIndex;
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        //We will merge 2 heap vectors and then heapify the concatenated vector
        //It is simple af
        vector<int> c(a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());
        //Let us heapify vector c
        for(int i=(c.size()/2)-1; i>=0; i--){
            heapify(c, i, c.size());
        }
        return c;
    }
};