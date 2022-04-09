#include <bits/stdc++.h>
using namespace std;
long long int res = 0;

long long int dfs(int src, vector<int> adj[], int i, vector<int> &t);

long long int dfs(int src, vector<int> adj[], int i, vector<int> &t)
{
  if (i == src)
    return 1;

  long long int total = 0;
  for (auto a : adj[i])
  {
    t[i] = 1;
    total += dfs(src, adj, a, t);
    t[i] = 0;
  }
  return total;
}
long long solve(int n)
{
  // Write your code here

  vector<int> adj[n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (((j + 1) % (i + 1)) == 0 && i!=j)
      {
        adj[i].push_back(j);
      }
    }
  }

  vector<int> t(n, 0);
  t[0] = 1;

  long long int ans = dfs(n - 1, adj, 0, t);
  return ans;
}

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  // int T;
  // cin >> T;
  // for (int t_i = 0; t_i < T; t_i++)
  // {
    int N;
    cin >> N;

    long long out_;
    out_ = solve(N);
    cout << out_;
    cout << "\n";
  // }
}