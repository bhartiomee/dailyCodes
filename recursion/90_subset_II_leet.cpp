set<vector<int>> st;
vector<vector<int>> ans;
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
  vector<int> tmp;
  int idx = 0;
  sort(nums.begin(), nums.end());
  findSets(idx, tmp, nums, nums.size());
  ans.assign(st.begin(), st.end());
  return ans;
}

void findSets(int idx, vector<int> &tmp, vector<int> &nums, int n)
{
  if (idx == n)
  {
    st.insert(tmp);
    return;
  }

  tmp.push_back(nums[idx]);
  findSets(idx + 1, tmp, nums, n);
  tmp.pop_back();
  findSets(idx + 1, tmp, nums, n);
}