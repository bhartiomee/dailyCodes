vector<vector<bool>> isPrq(n, vector<bool>(n, false));
queue<int> q;
vector<int> adj[n];
vector<int> ind(n, 0);

for (int i = 0; i < prq.size(); i++)
{
  ind[prq[i][1]]++;
  adj[prq[i][0]].push_back(prq[i][1]);
  isPrq[prq[i][0]][prq[i][0]] = true;
}

for (int i = 0; i < ind.size(); i++)
{
  if (ind[i] == 0)
    q.push(i);
}

while (!q.empty())
{
  int node = q.front();
  q.pop();
  for (auto c : adj[node])
  {
    if (--ind[c] == 0)
      q.push(c);
    for (int i = 0; i < n; i++)
    {
      if (isPrq[i][node])
      {
        isPrq[i][c] = true;
      }
    }
  }
}
vector<bool> ans;
for (auto q : queries)
{
  ans.push_back(isPrq[q[0]][q[1]]);
}
return ans;
}