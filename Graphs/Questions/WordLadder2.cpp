# include<vector>
# include <unordered_set>
# include <unordered_map>
# include <iostream>
# include <queue>
using namespace std;

// TLE Solution
class Solution1 {
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set <string> st (wordList.begin(), wordList.end());
            queue<vector<string>> q;
            q.push({beginWord});
            vector<string> usedOnLevel;
            usedOnLevel.push_back(beginWord);
            int level=0;
            vector<vector<string>> ans;
            while(!q.empty()){
                vector<string> vec=q.front();
                q.pop();
                if(vec.size()>level){
                    level++;
                    for(auto it:usedOnLevel){
                        st.erase(it);
                    }
                }
                string word = vec.back();
                if(word==endWord){
                    if(ans.size()==0){
                        ans.push_back(vec);
                    }else if(ans[0].size()==vec.size()){
                        ans.push_back(vec);
                    }
                }
                for(int i=0;i<word.length(); i++){
                    char ch = word[i];
                    for(char j='a';j<'z';j++){
                        word[i]=j;
                        if(st.find(word)!=st.end()){
                            vec.push_back(word);
                            q.push(vec);
                            usedOnLevel.push_back(word);
                            vec.pop_back();
                        }
                    }
                    word[i]=ch;
                }
            }
            return ans;
        }
    };

// Optimized Solution
class Solution {
    unordered_map<string, int>mpp;
    vector<vector<string>> ans;
    string b;
private:
    void dfs(string word, vector<string> &seq){
        if(word==b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps=mpp[word];
        int size=word.size();
        for(int i=0;i<size;i++){
            char orig=word[i];
            for(char j='a';j<='z';j++){
                word[i]=j;
                if(mpp.find(word) != mpp.end() && mpp[word]+1==steps){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i]=orig;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push({beginWord});
        b=beginWord;
        unordered_set <string> st (wordList.begin(), wordList.end());
        mpp[beginWord]=1;
        int size=beginWord.size();
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if(word==endWord) break;
            for(int i=0;i<size;i++){
                char orig=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word]=steps+1;
                    }
                }
                word[i]=orig;
            }
        }
        if(mpp.find(endWord) != mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};