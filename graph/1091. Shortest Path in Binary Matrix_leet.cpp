// bfs+dp
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
  int ans = INT_MAX;
  vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
  int n = grid.size();
  queue<pair<int, int>> q;
  if (grid[0][0] || grid[n - 1][n - 1])
    return -1;
  q.push({0, 0});

  grid[0][0] = 1;

  while (!q.empty())
  {
    auto curr = q.front();
    q.pop();

    for (auto d : dirs)
    {
      int x = d.first + curr.first;
      int y = d.second + curr.second;
      if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0)
      {
        q.push({x, y});
        grid[x][y] = grid[curr.first][curr.second] + 1;
      }
    }
  }
  return grid[n - 1][n - 1] ? grid[n - 1][n - 1] : -1; // as we are already handling the case if last cell is 1, so another possibility is that is contains 0, and after all he calcuation if it is still 0 that means we could not reach that cell so -1 and if it is non zero retun the value
}
