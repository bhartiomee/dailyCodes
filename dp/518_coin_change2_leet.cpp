// brte force
int cutRod(int price[], int n)
{
  // code here
  int dp[n + 1][n + 1];

  for (int j = 0; j <= n; j++)
    dp[j][0] = 0;
  for (int i = 0; i <= n; i++)
    dp[0][i] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i <= j)
        dp[i][j] = max(price[i - 1] + dp[i][j - i], dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][n];
}
// dp
int change(int amount, vector<int> &coins)
{
  int n = coins.size();
  int dp[n + 1][amount + 1];

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= amount; j++)
    {
      if (i == 0)
        dp[i][j] = 0;
      if (j == 0)
        dp[i][j] = 1;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= amount; j++)
    {
      if (coins[i - 1] <= j)
      {
        dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
      }
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  return dp[n][amount];
}
