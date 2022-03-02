bool solve(bool graph[101][101], int m, int v, int node, int color[]);
bool possible(int col, bool graph[101][101], int node, int v, int color[]);

bool graphColoring(bool graph[101][101], int m, int V)
{
  // your code here

  int color[V] = {0};
  if (solve(graph, m, V, 0, color))
    return true;
  else
    return false;
}
bool solve(bool graph[101][101], int m, int v, int node, int color[])
{
  if (node == v)
    return true;

  for (int col = 1; col <= m; col++)
  {
    if (possible(col, graph, node, v, color))
    {
      color[node] = col;
      if (solve(graph, m, v, node + 1, color))
        return true;
      color[node] = 0;
    }
  }
  return false;
}

bool possible(int col, bool graph[101][101], int node, int v, int color[])
{
  for (int i = 0; i < v; i++)
  {
    if (i != node && graph[i][node] == 1 && color[i] == col)
      return false;
  }
  return true;
}
