#include <bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2, int m, int n);
vector<vector<int>> dp;
string shortestCommonSupersequence(string str1, string str2)
{
  int m = str1.length();
  int n = str2.length();

  dp.resize(m + 1, vector<int>(n + 1));

  lcs(str1, str2, m, n);

  int i = m;
  int j = n;
  string ans = "";
  while (i > 0 && j > 0)
  {
    if (str1[i - 1] == str2[j - 1])
    {
      ans += str1[i - 1];
      i--;
      j--;
    }
    else
    {
      if (dp[i - 1][j] > dp[i][j - 1])
      {

        ans += str1[i - 1];
        i--;
      }
      else
      {
        ans += str2[j - 1];
        j--;
      }
    }
  }

  while (i > 0)
  {
    ans += str1[i - 1];
    i--;
  }
  while (j > 0)
  {
    ans += str2[j - 1];
    j--;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

void lcs(string s1, string s2, int m, int n)
{
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
    }
  }

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
}

int main()
{
  string s1 = "abac";
  string s2 = "cab";
  shortestCommonSupersequence(s1, s2);
}