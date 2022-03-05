/*
Method1:Recursion
TC:exponential, becuse we are considering all the subsets
*/
bool ans = false;
bool isSubsetSum(int N, int arr[], int sum)
{
  // code here
  solve(0, N, arr, sum);
  return ans;
}

void solve(int idx, int n, int arr[], int sum)
{
  if (sum == 0)
  {
    ans = true;
    return;
  }
  if (idx == n)
    return;
  if (sum < 0)
    return;

  solve(idx + 1, n, arr, sum - arr[idx]);
  solve(idx + 1, n, arr, sum);
}

/*
Recusrsion + memoisation
TC:O(n*sum)
SC:O(n*sum)
*/
int dp[101][10001];
bool isSubsetSum(int n, int arr[], int sum)
{
  // code here
  memset(dp, -1, sizeof(dp));
  return solve(n, arr, sum);
}
int solve(int n, int arr[], int sum)
{
  if (sum == 0)
    return 1;
  if (n <= 0)
    return 0;

  if (dp[n - 1][sum] != -1)
    return dp[n - 1][sum];

  if (arr[n - 1] <= sum)
  {
    return dp[n - 1][sum] = solve(n - 1, arr, sum) || solve(n - 1, arr, sum - arr[n - 1]);
  }
  else
    return dp[n - 1][sum] = solve(n - 1, arr, sum);
}

/*
DP-Top down
TC:O(n*sum)
SC:O(n*sum)
*/
bool isSubsetSum(int n, int arr[], int sum)
{
  // code here
  int dp[n + 1][sum + 1];

  for (int i = 0; i <= sum; i++)
    dp[0][i] = false;

  for (int i = 0; i <= n; i++)
    dp[i][0] = true;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= sum; j++)
    {

      if (arr[i - 1] <= j)
      {
        dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
      }
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][sum];
}
