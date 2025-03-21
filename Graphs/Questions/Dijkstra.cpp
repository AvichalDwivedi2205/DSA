# include<vector>
# include <queue>
# include <iostream>
# include <set>
using namespace std;

class Solution {
    public:
      // Function to find the shortest distance of all the vertices
      // from the source vertex src.
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
          // Code here
          priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
          vector<int> dist(adj.size(), 1e9);
          dist[src]=0;
          pq.push({0,src});
          while(!pq.empty()){
              int dis = pq.top().first;
              int node = pq.top().second;
              pq.pop();
              for(auto nbr:adj[node]){
                  if(dist[nbr.first]>dist[node]+nbr.second){
                      dist[nbr.first]=dist[node]+nbr.second;
                      pq.push({dist[nbr.first],nbr.first});
                  }
              }
          }
          return dist;
      }
  };

  class Solution_Set {
    public:
      // Function to find the shortest distance of all the vertices
      // from the source vertex src.
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
          // Code here
          set<pair<int,int>> st;
          vector<int> dist(adj.size(), 1e9);
          dist[src]=0;
          st.insert({0,src});
          while(!st.empty()){
              auto ele = *(st.begin());
              int dis = ele.first;
              int node = ele.second;
              st.erase(ele);
              for(auto nbr:adj[node]){
                  if(dist[nbr.first]>dist[node]+nbr.second){
                      dist[nbr.first]=dist[node]+nbr.second;
                      st.insert({dist[nbr.first],nbr.first});
                  }
              }
          }
          return dist;
      }
  };