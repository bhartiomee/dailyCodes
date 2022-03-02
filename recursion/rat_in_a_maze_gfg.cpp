vector<string> ans;
vector<string> findPath(vector<vector<int>> &m, int n)
{
  // Your code goes here
  string path = "";
  solve(path, 0, 0, m);
  return ans;
}

void solve(string path, int i, int j, vector<vector<int>> &m)
{

  if (!isValid(i, j, m))
    return;

  if (i == m.size() - 1 && j == m.size() - 1)
  {
    ans.push_back(path);
    return;
  }

  m[i][j] = 0;
  // up
  solve(path + 'U', i - 1, j, m);
  // down
  solve(path + 'D', i + 1, j, m);
  // left
  solve(path + 'L', i, j - 1, m);
  // right
  solve(path + 'R', i, j + 1, m);
  m[i][j] = 1;
}

bool isValid(int i, int j, vector<vector<int>> &m)
{
  return (i >= 0 && j >= 0 && i < m.size() && j < m.size() && m[i][j] == 1);
}
