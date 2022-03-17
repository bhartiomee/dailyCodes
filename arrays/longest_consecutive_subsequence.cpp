int longestConsecutive(vector<int> &nums)
{
  unordered_set<int> mp;
  int n = nums.size();

  for (int i = 0; i < n; i++)
  {
    mp.insert(nums[i]);
  }

  int maxLength = 0;

  for (int i = 0; i < n; i++)
  {
    if (mp.find(nums[i] - 1) == mp.end())
    {
      int cnt = 1;
      int x = nums[i];
      while (mp.find(x + 1) != mp.end())
      {
        x = x + 1;
        cnt++;
      }
      maxLength = max(maxLength, cnt);
    }
  }
  return maxLength;
}
