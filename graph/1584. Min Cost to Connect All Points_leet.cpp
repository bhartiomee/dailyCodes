int minCostConnectPoints(vector<vector<int>> &points)
{
  int n = points.size();
  vector<vector<int>> cost(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cost[i][j] = calcDist(points[i][0], points[j][0], points[i][1], points[j][1]);
    }
  }
  int ans = minSpan(n, cost);
  return ans;
}

int minSpan(int n, vector<vector<int>> &cost)
{
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
    mst[u] = 1;
    pq.pop();

    for (int v = 0; v < n; v++)
    {
      int wt = cost[u][v];
      if (!mst[v] && wt < key[v])
      {
        key[v] = wt;
        par[v] = u;
        pq.push({key[v], v});
      }
    }
  }
  int totCost = 0;
  for (int i = 0; i < n; i++)
  {
    totCost += key[i];
  }
  return totCost;
}

int calcDist(int x1, int x2, int y1, int y2)
{
  return (abs(x1 - x2) + abs(y1 - y2));
}