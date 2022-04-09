// union find
class DSU
{
  vector<int> par, r, size;

public:
  DSU(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        par.push_back(i * n + j);
        r.push_back(0);
        size.push_back(1);
      }
    }
  }

  int find(int x)
  {
    if (x == par[x])
      return x;
    return par[x] = find(par[x]);  //path compression
  }

  int Union(int x, int y)
  {
    int px = find(x);
    int py = find(y);
    if (px != py)
    {
      if (r[px] < r[py])
      {
        par[px] = py;
        size[py] += size[px];
        return size[py];
      }
      else if (r[py] < r[px])
      {
        par[py] = px;
        size[px] += size[py];
        return size[px];
      }
      else
      {
        par[py] = px;
        r[px]++;
        size[px] += size[py];
        return size[px];
      }
    }
    else
      return size[px];
  }
  int getSize(int x)
  {
    return size[find(x)];
  }
};

class Solution
{
public:
  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    if (m == 0 || n == 0)
      return 0;
    DSU uf(grid);
    int maxArea = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          grid[i][j] = 0;
          maxArea = max(maxArea, uf.getSize(i * n + j));
          if (i > 0 && grid[i - 1][j] == 1)
            maxArea = max(maxArea, uf.Union(i * n + j, (i - 1) * n + j));
          if (j > 0 && grid[i][j - 1] == 1)
            maxArea = max(maxArea, uf.Union(i * n + j, i * n + (j - 1)));
          if (j + 1 < n && grid[i][j + 1] == 1)
            maxArea = max(maxArea, uf.Union(i * n + j, i * n + (j + 1)));
          if (i + 1 < m && grid[i + 1][j] == 1)
            maxArea = max(maxArea, uf.Union(i * n + j, (i + 1) * n + j));
        }
      }
    }

    return maxArea;
  }
};

// dfs
vector<vector<int>> vis;
int maxAreaOfIsland(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();
  vis.resize(m, vector<int>(n, 0));

  int area = 0, maxArea = 0;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!vis[i][j] && grid[i][j] == 1)
      {
        area = dfs(i, j, grid);
        maxArea = max(area, maxArea);
      }
    }
  }
  return maxArea;
}

int dfs(int r, int c, vector<vector<int>> &grid)
{
  if (!isValid(r, c, grid))
    return 0;
  vis[r][c] = 1;

  return 1 + dfs(r + 1, c, grid) + dfs(r - 1, c, grid) + dfs(r, c + 1, grid) + dfs(r, c - 1, grid);
}
bool isValid(int r, int c, vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();
  return (r >= 0 && c >= 0 && r < m && c < n && grid[r][c] == 1 && !vis[r][c]);
}
