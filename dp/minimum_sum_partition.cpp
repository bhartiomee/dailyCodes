/*
We need to minimize abs(s1-s2), s1 and s2=>sum of parted subsets of a array
 highest sum we can get is total_sum_of_array

 so we can check now for all the subsetsums that if it can be a valid answer, little optimisation can be to find out only eligible sum, Eg fo [1,3] 2 can never be an eligible subset sum

 one more thing is that s1=>totalSum-s2=> s1-s2 = totalSum-s2-s1=>toatlSum-2s2;

 now we need to find oly one eligible subet, we need to find "IF A SUBSET CAN HAVE A SUM 'x' "=>subset sum problem,

 so we know that last row las column od dp gives eh answer,
 but we make a dp for dp[n+1][totalSum],
 the row of each colums would tell us that either 'x' that belongs the sum range number line is eligible sum or not, we ust need to store them seperatly,
 and find minimum possible value

*/
vector<int> eligibleSum;
int minDifference(int arr[], int n)
{
  // Your code goes here
  int total_sum = 0;
  for (int i = 0; i < n; i++)
  {
    total_sum += arr[i];
  }

  isEligibleSum(arr, n, total_sum);
  int ans = INT_MAX;
  for (int i = 0; i < eligibleSum.size(); i++)
  {
    ans = min(ans, (total_sum - 2 * eligibleSum[i]));
  }

  return ans;
}

//code of susbet sum
void isEligibleSum(int arr[], int n, int sum)
{
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

  for (int j = 0; j <= sum / 2; j++) 
  {
    if (dp[n][j])
      eligibleSum.push_back(j);
  }
}
