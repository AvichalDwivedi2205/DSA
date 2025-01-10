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
    string reorganizeString(string s) {
        int freq[26] = {0};

        //Count frequency of all characters in string
        for(int i=0;i<s.length(); i++){
            freq[s[i]-'a']++; 
        }

        //Push all the characters in max heap
        priority_queue<Info, vector<Info>, compare> maxHeap;
        //For max heap
        //Push all characters in the heap where the frequency is greater than zero
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                Info temp(i+'a', freq[i]);
                maxHeap.push(temp);
            }
        }
        string ans="";
        while(maxHeap.size()>1){
            Info first=maxHeap.top();
            maxHeap.pop();
            Info second = maxHeap.top(); maxHeap.pop();
            ans.push_back(first.val);
            first.count--;
            ans.push_back(second.val);
            second.count--;
            if(first.count>0) maxHeap.push(first);
            if(second.count>0) maxHeap.push(second);
        }

        //If ek element bacha hai alag se handle karo
        if(maxHeap.size()==1){
            Info first = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;
            if(first.count != 0)
            return "";
        }
        return ans;
    }
};