// https://leetcode.com/problems/sum-of-unique-elements/
int sumOfUnique(vector<int> &nums)
{
  int n = nums.size();
  unordered_map<int, int> cnt;
  for (int i = 0; i < n; i++)
  {
    cnt[nums[i]]++;
  }
  int sum = 0;
  for (auto c : cnt)
  {
    if (c.second == 1)
      sum += c.first;
  }
  return sum;
}