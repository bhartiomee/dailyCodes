#include <bits/stdc++.h>
using namespace std;
vector<string> summaryRanges(vector<int> &nums)
{
  int prev = 0;
  vector<string> ans;
  int n = nums.size();
  for (int i = 1; i < n; i++)
  {
    int curr = nums[i];
    if (nums[i] - nums[i-1] == 1)
      curr = nums[i];
    else
    {
      if (prev != curr)
        ans.push_back(to_string(nums[prev]) + "->" + to_string(nums[i - 1]));
      else
        ans.push_back(to_string(curr));  
      if (i < n)
        prev = i + 1;
    }
  }
  return ans;
}

int main()
{
  vector<int> nums = {0, 1, 2, 4, 5, 7};
  summaryRanges(nums);
}