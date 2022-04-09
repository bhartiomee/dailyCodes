class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    int n = nums.size();
    if (k == n)
      return nums;
    unordered_map<int, int> numToFreq;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
      numToFreq[nums[i]]++;
    }
    vector<int> ans;
    for (auto p : numToFreq)
    {
      pq.push(make_pair(p.second, p.first));
      if (pq.size() > (int)numToFreq.size() - k)
      {
        ans.push_back(pq.top().second);
        pq.pop();
      }
    }

    return ans;
  }
};
