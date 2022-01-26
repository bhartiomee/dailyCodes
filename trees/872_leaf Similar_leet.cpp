bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
  stack<int> stk1, stk2;
  dfs(root1, stk1);
  dfs(root2, stk2);

  if (stk1.size() != stk2.size())
    return false;

  while (!stk2.empty() && !stk2.empty())
  {
    if (stk1.top() != stk2.top())
      return false;
    stk1.pop();
    stk2.pop();
  }
  return true;
}

void dfs(TreeNode *root, stack<int> &stk)
{
  if (!root)
    return;
  if (!root->left && !root->right)
  {
    stk.push(root->val);
    return;
  }
  dfs(root->left, stk);
  dfs(root->right, stk);
}