vector<bool> vis;
bool validPath(int n, vector<vector<int>> &edges, int src, int d)
{
  vector<int> adj[n + 1];
  vis.resize(n + 1, false);
  for (int i = 0; i < edges.size(); i++)
  {

    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
  }

  return dfs(adj, src, d);
}

bool dfs(vector<int> adj[], int node, int des)
{
  if (node == des)
    return true;
  if (vis[node])
    return false;
  vis[node] = true;

  for (int i = 0; i < adj[node].size(); i++)
  {
    if (dfs(adj, adj[node][i], des))
      return true;
  }
  return false;
}
