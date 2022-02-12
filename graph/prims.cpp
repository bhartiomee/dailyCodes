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
  key[0] = 0;
  par[0] = -1;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({key[0], 0});

  while (!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();
    mst[u] = 1;
    for (auto it : adj[u])
    {
      int v = it[0];
      int wt = it[1];
      if (!mst[v] && wt < key[v])
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