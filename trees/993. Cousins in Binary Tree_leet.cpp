//BFS
bool isCousins(TreeNode *root, int x, int y)
{
  bool ans = false;

  queue<pair<TreeNode *, int>> q;
  q.push({root, -1});

  while (!q.empty() && !ans)
  {
    int n = q.size();
    bool foundOne = false;
    int foundPar;
    while (n--)
    {
      TreeNode *node = q.front().first;
      int par = q.front().second;
      q.pop();
      bool tmp = (node->val == x || node->val == y);
      if (tmp && foundOne)
      {
        if (par != foundPar)
        {
          ans = true;
          break;
        }
      }
      else
      {
        if (tmp)
        {
          foundOne = true;
          foundPar = par;
        }
      }
      if (node->left)
        q.push({node->left, node->val});
      if (node->right)
        q.push({node->right, node->val});
    }
  }
  return ans;
}
