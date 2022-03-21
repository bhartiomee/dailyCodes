int cnt = INT_MAX;
int coinChange(vector<int> &coins, int amount)
{
  solve(0, coins, amount, 0);
  if (cnt == INT_MAX)
    return -1;
  else
    return cnt;
}

void solve(int idx, vector<int> &coins, int amount, int noOfCoins)
{
  if (idx == coins.size())
  {
    if (amount == 0)
    {
      cnt = min(cnt, noOfCoins);
    }
    return;
  }
  if (amount < 0)
    return;
  solve(idx, coins, amount - coins[idx], noOfCoins + 1);
  solve(idx + 1, coins, amount, noOfCoins);
}

// dp
int n = coins.size();
int dp[n + 1][amount + 1];

for (int i = 0; i <= n; i++)
{
  for (int j = 0; j <= amount; j++)
  {
    if (i == 1)
    {
      dp[i][j] = (amount % coins[0] == 0) ? 1 : INT_MAX - 1;
    }
    if (i == 0)
      dp[i][j] = INT_MAX - 1;
    if (j == 0)
      dp[i][j] = 0;
  }
}

for (int i = 1; i <= n; i++)
{
  for (int j = 1; j <= amount; j++)
  {
    if (coins[i - 1] <= j)
    {
      dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]); // as we are adding 1 here ,so we intitialized with INT_MAX-1, to avoid integer overflow
    }
    else
      dp[i][j] = dp[i - 1][j];
  }
}

if (dp[n][amount] == INT_MAX - 1)
  return -1;
return dp[n][amount];
}
