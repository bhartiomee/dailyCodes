#include <bits/stdc++.h>
using namespace std;

int spanningTree(int n, vector<vector<int>> adj[])
{
  // code here
  int key[n];
  int mst[n];
  int par[n];
  for (int i = 0; i < n; i++)
  {
    key[i] = INT_MAX;
    mst[i] = 0;
  }
  key[0] = 0;//min distance from 0 to itself
  par[0] = -1;//as 0 is the src so its parent is -1

//we use pq, to have the min key value
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//min heap
  pq.push({key[0], 0}); //push min weight node

  while (!pq.empty())
  {
    int u = pq.top().second; //from u
    pq.pop();
    mst[u] = 1;//u has been marked as visited
    for (auto it : adj[u])
    {
      int v = it[0]; //to v
      int wt = it[1]; //ka wt
      if (!mst[v] && wt < key[v]) //if we reach "it" with a lesser weight we update its wt and also its parent
      {
        key[v] = wt;
        par[v] = u;
        pq.push({key[v], v});
      }
    }
  }

  //if told to find min weight sum
  int minSum = 0;
  for (int i = 0; i < n; i++)
  {
    minSum += key[i];
  }
 
}
