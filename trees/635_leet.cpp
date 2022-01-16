vector<double> averageOfLevels(TreeNode *root)
{
  vector<double> avg;
  TreeNode *r = root;
  queue<TreeNode *> q;
  q.push(r);
  while (!q.empty())
  {
    int n = q.size();
    double sz = n;
    double sum = 0;
    while (n--)
    {
      TreeNode *tmp = q.front();
      q.pop();
      sum += tmp->val;
      if (tmp->left)
        q.push(tmp->left);
      if (tmp->right)
        q.push(tmp->right);
    }
    avg.push_back(sum / sz);
  }
  return avg;
}