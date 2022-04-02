#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int>> &grid, queue<pair<pair<int, int>, int>> &q);
vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int shortestBridge(vector<vector<int>> &grid)
{
  queue<pair<pair<int, int>, int>> q;

  int flag = 0;
  for (int i = 0; i < grid.size(); i++)
  {
    if (flag)
      break;
    for (int j = 0; j < grid[0].size(); j++)
    {
      if (grid[i][j] == 1)
      {
        dfs(i, j, grid, q);
        flag = 1;
        break;
      }
    }
  }

  while (!q.empty())
  {
    auto t = q.front();
    auto tmp = t.first;
    int len = t.second;

    q.pop();
    for (auto d : dirs)
    {
      int x = tmp.first + d.first;
      int y = tmp.second + d.second;

      if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] != 2)
      {
        if (grid[x][y] == 1)
          return len;
        else
        {
          q.push({{x, y}, len + 1});
          grid[x][y] = 2;
        }
      }
    }
  }

  return -1;
}
void dfs(int i, int j, vector<vector<int>> &grid, queue<pair<pair<int, int>, int>> &q)
{
  grid[i][j] = 2;
  q.push({{i, j}, 0});

  for (auto d : dirs)
  {
    int x = i + d.first;
    int y = j + d.second;
    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1)
    {
      dfs(x, y, grid, q);
    }
  }
}

int main()
{
  vector<vector<int>> grid = {{1, 1, 1, 1, 1},
                              {1, 0, 0, 0, 1},
                              {1, 0, 1, 0, 1},
                              {1, 0, 0, 0, 1},
                              {1, 1, 1, 1, 1}};
  shortestBridge(grid);
}