// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Function to find number of strongly connected components in the graph.
  int kosaraju(int v, vector<int> adj[])
  {
    // code here
    stack<int> stk;
    vector<int> vis(v, 0);
    for (int i = 0; i < v; i++)
    {
      if (!vis[i])
        topoSort(i, adj, vis,stk);
    }
    vector<int> adjRev[v];
    for (int i = 0; i < v; i++)
    {
      vis[i]=0;
      for (auto j : adj[i])
      {
        adjRev[j].push_back(i);
      }
    }

    int scc = 0;

    while (!stk.empty())
    {
      int node = stk.top();
      stk.pop();
      if (!vis[node])
      {
        dfs(node, adjRev, vis);
        scc++;
      }
    }
    return scc;
  }

  void topoSort(int node, vector<int> adj[], vector<int> &vis,stack<int> &stk)
  {
    vis[node] = 1;
    for (auto a : adj[node])
    {
      if (!vis[a])
        topoSort(a, adj, vis,stk);
    }
    stk.push(node);
  }
  void dfs(int node, vector<int> adj[], vector<int> &vis)
  {
    vis[node] = 1;
    for (auto a : adj[node])
    {
      if (!vis[a])
        dfs(a, adj, vis);
    }
  }
};

// { Driver Code Starts.

int main()
{
  int V, E;
  cin >> V >> E;

  vector<int> adj[V];

  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  Solution obj;
  cout << obj.kosaraju(V, adj) << "\n";

  return 0;
}

// } Driver Code Ends