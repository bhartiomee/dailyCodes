int findTargetSumWays(vector<int> &nums, int target)
{
  int totalSum = 0;
  totalSum = accumulate(nums.begin(), nums.end(), totalSum);

  if (target > totalSum || (totalSum + target) % 2 != 0)
    return 0;
  int s = (totalSum + target) / 2;

  return countSubsets(nums, abs(s));
}

int countSubsets(vector<int> nums, int sum)
{
  int n = nums.size();
  int dp[n + 1][sum + 1];

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= sum; j++)
    {
      if (i == 0)
        dp[i][j] = 0;
      if (j == 0)
        dp[i][j] = 1;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= sum; j++)
    {
      if (nums[i - 1] <= j)
      {
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
      }
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][sum];
}
