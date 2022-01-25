//iterative
vector<int> postorderTraversal(TreeNode *root)
{
  if (!root)
    return {};
  TreeNode *curr = root;
  vector<int> ans;
  stack<TreeNode *> stk;
  TreeNode *tmp;

  while (curr || !stk.empty())
  {
    if (curr)
    {
      stk.push(curr);
      curr = curr->left;
    }
    else
    {
      tmp = stk.top();
      if (!tmp->right)
      {
        stk.pop();
        ans.push_back(tmp->val);
        while (!stk.empty() && tmp == stk.top()->right)
        {
          tmp = stk.top();
          stk.pop();
          ans.push_back(tmp->val);
        }
      }
      else
      {
        curr = tmp->right;
      }
    }
  }
  return ans;
}