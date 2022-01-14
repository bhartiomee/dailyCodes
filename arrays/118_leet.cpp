// https://leetcode.com/problems/pascals-triangle/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
  int n = numRows;
  vector<vector<int>> triangle;

  for (int i = 0; i < n; i++)
  {
    vector<int> tmp;
    for (int j = 0; j <= i; j++)
    {
      if (j == 0 || i == j)
      {
        tmp.push_back(1);
      }
      else
      {
        if (i > 0 && j > 0)
          tmp.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
      }
    }
    triangle.push_back(tmp);
  }
  return triangle;
}
int main()
{
  int n;
  cin >> n;
  vector<vector<int>> ans = generate(n);
  return 1;
}
