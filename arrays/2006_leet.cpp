
// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/submissions/
class Solution
{
public:
  int countKDifference(vector<int> &nums, int k)
  {
    int cnt[101] = {0};
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      cnt[nums[i]]++;
    }

    for (int i = 0; i < 101; i++)
    {
      if ((i + k) <= 100)
        ans += cnt[i] * cnt[i + k];
    }

    return ans;
  }
};
