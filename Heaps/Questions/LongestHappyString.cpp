# include <iostream>
# include <queue>
using namespace std;

class Info{
    public:
    char val;
    int count;
    Info(char ch, int count){
        this->val=ch;
        this->count=count;
    }
};

class compare{
    public:
    bool operator()(Info a, Info b){
        return a.count<b.count;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Info, vector<Info>, compare> pq;
        if(a>0){
            Info aHeap('a', a);
            pq.push(aHeap);
        }
        if(b>0){
            Info bHeap('b', b);
            pq.push(bHeap);
        } 
        if(c>0){
            Info cHeap('c', c);
            pq.push(cHeap);
        }
        string ans="";
        while(pq.size()>1){
            Info first=pq.top();pq.pop();
            Info second = pq.top(); pq.pop();
            if(first.count>=2){
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count-=2;
            }else{
                ans.push_back(first.val);
                first.count--;
            }
            if(second.count>=2 && second.count>=first.count){
                ans.push_back(second.val);
                ans.push_back(second.val);
                second.count-=2;
            }else{
                ans.push_back(second.val);
                second.count--;
            }
            if(first.count>0){
                pq.push(first);
            }
            if(second.count>0){
                pq.push(second);
            }
        }
        if(pq.size()==1){
            Info first = pq.top();
            pq.pop();
            if(first.count>=2){
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count-=2;
            }else{
                ans.push_back(first.val);
                first.count--;
            }
        }
        return ans;
    }
};