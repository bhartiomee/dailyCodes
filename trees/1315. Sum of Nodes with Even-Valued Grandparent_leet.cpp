//bfs
int sumEvenGrandparent(TreeNode *root)
{
  queue<pair<TreeNode *, pair<int, int>>> q;

  q.push({root, {-1, -1}});
  int sum = 0;
  while (!q.empty())
  {
    TreeNode *node = q.front().first;
    int par = q.front().second.first;
    int gpar = q.front().second.second;
    q.pop();

    if (gpar > 0 && gpar % 2 == 0)
      sum += node->val;
    if (node->left)
    {
      q.push({node->left, {node->val, par}});
    }
    if (node->right)
    {
      q.push({node->right, {node->val, par}});
    }
  }
  return sum;
}

//dfs
int sum = 0;
int sumEvenGrandparent(TreeNode *root)
{
  traverse(root, -1, -1);
  return sum;
}

void traverse(TreeNode *root, int par, int gpar)
{
  if (!root)
    return;

  if (gpar > 0 && gpar % 2 == 0)
    sum += root->val;

  traverse(root->left, root->val, par);
  traverse(root->right, root->val, par);
}
