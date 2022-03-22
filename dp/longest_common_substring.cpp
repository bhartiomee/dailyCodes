//
// recusrion
int ans = 0;
int findLength(vector<int> &nums1, vector<int> &nums2)
{
  solve(nums1, nums2, 0, 0);
  return ans;
}

int solve(vector<int> &nums1, vector<int> &nums2, int i, int j)
{
  if (i == nums1.size() || j == nums2.size())
    return 0;

  solve(nums1, nums2, i + 1, j);
  solve(nums1, nums2, i, j + 1);

  int cnt = (nums1[i] == nums2[j]) ? 1 + solve(nums1, nums2, i + 1, j + 1) : 0;

  ans = max(ans, cnt);
  return cnt;
}

// memo+rec
int ans = 0;
int memo[1001][1001];
int findLength(vector<int> &nums1, vector<int> &nums2)
{
  memset(memo, -1, sizeof(memo));
  solve(nums1, nums2, 0, 0);
  return ans;
}

int solve(vector<int> &nums1, vector<int> &nums2, int i, int j)
{
  if (i == nums1.size() || j == nums2.size())
    return 0;

  if (memo[i][j] != -1)
    return memo[i][j];
  solve(nums1, nums2, i + 1, j);
  solve(nums1, nums2, i, j + 1);
  memo[i][j] = (nums1[i] == nums2[j]) ? 1 + solve(nums1, nums2, i + 1, j + 1) : 0;

  ans = max(ans, memo[i][j]);
  return memo[i][j];
}

// top down
int findLength(vector<int> &nums1, vector<int> &nums2)
{
  int m = nums1.size();
  int n = nums2.size();
  int dp[m + 1][n + 1];

  int ans = 0;
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
      if (nums1[i - 1] == nums2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        ans = max(ans, dp[i][j]); // unlike subsequnce we are strog max because substring can be anywhere in the matrix and not juts in the end
      }
      else
        dp[i][j] = 0;
    }
  }
  return ans;
}
