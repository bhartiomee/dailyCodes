#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<bool> vis;
int n;
void dfs(int s, vector<int> &tmp, vector<int> adj[]);
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
  n = graph.size();
  vector<int> adj[n + 1];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < graph[i].size(); j++)
    {
      adj[i].push_back(graph[i][j]);
    }
  }
  vis.resize(n, false);
  vector<int> tmp;
  dfs(0, tmp, adj);
  return ans;
}

void dfs(int s, vector<int> &tmp, vector<int> adj[])
{
  tmp.push_back(s);
  if (vis[s])
    return;
  if (s == n - 1)
  {

    ans.push_back(tmp);
    return;
  }

  for (int i = 0; i < adj[s].size(); i++)
  {
    if (!vis[adj[s][i]])
    {
      dfs(adj[s][i], tmp, adj);
    }
    tmp.pop_back();
  }
}

int main()
{
  vector<vector<int>> g = {{1, 2}, {3}, {3}, {}};
  allPathsSourceTarget(g);
}