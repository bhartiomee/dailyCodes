class Solution
{
public:
  vector<vector<string>> ans;
  vector<vector<string>> solveNQueens(int n)
  {
    vector<string> tmp(n, string(n, '.'));

    solve(tmp, n, 0);
    return ans;
  }

  void solve(vector<string> &tmp, int n, int i)
  {

    if (i == n)
    {
      ans.push_back(tmp);
      return;
    }

    for (int c = 0; c < n; c++)
    {
      if (isValid(i, c, n, tmp))
      {
        tmp[i][c] = 'Q';
        solve(tmp, n, i + 1);
        tmp[i][c] = '.';
      }
    }
  }

  bool isValid(int r, int c, int n, vector<string> &tmp)
  {

    // check rows
    int j = 0;
    while (j < n)
    {
      if (tmp[r][j++] == 'Q')
        return false;
    }

    // check columns
    int i = 0;
    while (i < n)
    {
      if (tmp[i++][c] == 'Q')
        return false;
    }

    // major diagnoals
    i = r - 1;
    j = c - 1;
    while (i >= 0 && j >= 0)
    {
      if (tmp[i][j] == 'Q')
        return false;
      i--;
      j--;
    }

    // minor diagonals
    i = r - 1;
    j = c + 1;
    while (i >= 0 && j < n)
    {
      if (tmp[i][j] == 'Q')
        return false;
      i--;
      j++;
    }
    return true;
  }
};