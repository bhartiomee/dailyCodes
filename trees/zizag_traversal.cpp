// method 1
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
  vector<vector<int>> ans;
  if (!root)
    return {};
  queue<TreeNode *> q;
  int lev = 0;
  q.push(root);

  while (!q.empty())
  {
    int n = q.size();
    vector<int> vec;
    while (n--)
    {
      TreeNode *tmp = q.front();
      q.pop();
      vec.push_back(tmp->val);
      if (tmp->right)
        q.push(tmp->right);
      if (tmp->left)
        q.push(tmp->left);
    }
    if (lev % 2 == 0)
      reverse(vec.begin(), vec.end()); // reverse the array for even level
    ans.push_back(vec);
    lev++;
  }
  return ans;
}

// method 2
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
  vector<vector<int>> ans;
  if (!root)
    return {};
  queue<TreeNode *> q;
  bool ltr = true;
  q.push(root);

  while (!q.empty())
  {
    int n = q.size();
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
      TreeNode *tmp = q.front();
      q.pop();
      int idx = (ltr) ? i : n - i - 1; // insert from back in arry is ltr is false
      vec[idx] = tmp->val;
      if (tmp->left)
        q.push(tmp->left);
      if (tmp->right)
        q.push(tmp->right);
    }
    ans.push_back(vec);
    ltr = !ltr;
  }
  return ans;
}