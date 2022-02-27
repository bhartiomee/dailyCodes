// set<vector<int>>st;
vector<vector<int>> ans;
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  vector<int> tmp;
  sort(candidates.begin(), candidates.end());
  findCombinations(0, tmp, candidates, target);
  // ans.assign(st.begin(),st.end());
  return ans;
}

void findCombinations(int idx, vector<int> &tmp, vector<int> &cd, int target)
{
  if (target == 0)
  {
    ans.push_back(tmp);
    return;
  }
  if (idx == cd.size() || target - cd[idx] < 0)
    return;

  int num = cd[idx++];
  tmp.push_back(num);
  findCombinations(idx, tmp, cd, target - num);
  tmp.pop_back();
  while (idx < cd.size() && cd[idx] == num)
    idx++;
  findCombinations(idx, tmp, cd, target);
}
