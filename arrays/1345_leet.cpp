class Solution
{
public:
  int minJumps(vector<int> &arr)
  {
    int n = arr.size();
    if (n == 1)
      return 0;

    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
      if (mp.find(arr[i]) == mp.end())
        mp[arr[i]] = {i};
      else
        mp[arr[i]].push_back(i);
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<int> vis(n, 0);
    vis[0] = 1;
    while (!q.empty())
    {
      int idx = q.front().first;
      int cnt = q.front().second;
      q.pop();
      if (idx == n - 1)
        return cnt;
      else
      {
        if (idx > 0 && !vis[idx - 1])
        {
          q.push({idx - 1, cnt + 1});
          vis[idx - 1] = 1;
        }
        if (idx + 1 < n && !vis[idx + 1])
        {
          q.push({idx + 1, cnt + 1});
          vis[idx + 1] = 1;
        }
        for (int v : mp[arr[idx]])
          if (!vis[v])
          {
            q.push({v, cnt + 1});
            vis[v] = 1;
          }
        mp[arr[idx]] = {};
      }
    }
    return -1;
  }
};