# include <vector>
# include <queue>
# include <unordered_map>
# include <list>
# include <string>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string> &words) {
    unordered_map<char, list<char>> adjList;
    unordered_map<char, int> indegree;
    int n = words.size();
    for (string &word : words) {
        for (char c : word) {
            if (indegree.find(c) == indegree.end()) {
                indegree[c] = 0;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        string s1 = words[i];
        string s2 = words[i + 1];
        int len = min(s1.size(), s2.size());
        bool found = false;
        for (int j = 0; j < len; j++) {
            if (s1[j] != s2[j]) {
                adjList[s1[j]].push_back(s2[j]);
                indegree[s2[j]]++;
                found = true;
                break;
            }
        }
        if (!found && s1.size() > s2.size()) {
            return "";
        }
    }
    queue<char> q;
    for (auto &entry : indegree) {
        if (entry.second == 0) {
            q.push(entry.first);
        }
    }

    string ans;
    while (!q.empty()) {
        char ele = q.front();
        q.pop();
        ans.push_back(ele);

        for (char nbr : adjList[ele]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
    return (ans.length() == indegree.size()) ? ans : "";
}

};
