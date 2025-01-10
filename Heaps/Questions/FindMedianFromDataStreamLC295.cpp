# include <iostream>
# include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    double median=0.0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int minSize=mini.size();
        int maxSize=maxi.size();
        if(minSize==maxSize){
            if(num>median){
                mini.push(num);
                median=mini.top();
            }else{
                maxi.push(num);
                median=maxi.top();
            }
        }else if(minSize==maxSize+1){
            if(num>median){
                int minEle=mini.top();
                mini.pop();
                maxi.push(minEle);
                mini.push(num);
            }else{
                maxi.push(num);
            }
            median=(mini.top()+maxi.top())/2.0;
        }else{
            if(num>median){
                mini.push(num);
            }else{
                int maxEle = maxi.top();
                maxi.pop();
                maxi.push(num);
                mini.push(maxEle);
            }
            median=(mini.top()+maxi.top())/2.0;
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */