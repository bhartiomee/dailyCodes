vector<int> diagonal(Node *root)
{
  // your code here
  unordered_map<int, vector<int>> mp;
  int minm = INT_MAX;
  int maxm = INT_MIN;
  traverse(root, 0, 0, mp, minm, maxm);
  vector<int> ans;

  for (int i = minm; i <= maxm; i++)
  {
    for (int j = 0; j < mp[i].size(); j++)
    {
      ans.push_back(mp[i][j]);
    }
  }
  return ans;
}

void traverse(Node *root, int i, int j, unordered_map<int, vector<int>> &mp, int &minm, int &maxm)
{

  if (!root)
    return;
  minm = min(minm, i - j);
  maxm = max(maxm, i - j);

  mp[(i - j)].push_back(root->data);

  traverse(root->left, i + 1, j - 1, mp, minm, maxm);
  traverse(root->right, i + 1, j + 1, mp, minm, maxm);

  return;
}