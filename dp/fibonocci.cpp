// recusrion
int fib(int n)
{
  if (n == 0 || n == 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

// rec+memo
int fib(int n)
{
  int dp[n + 1];
  memset(dp, -1, sizeof(dp));
  solve(n, dp);
  return dp[n];
}
int solve(int n, int dp[])
{
  if (n == 0 || n == 1)
    return dp[n] = n;

  if (dp[n] != -1)
    return dp[n];
  else
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}