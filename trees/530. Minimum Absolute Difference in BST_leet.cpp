int ans = INT_MAX;
int prev = -1;
int getMinimumDifference(TreeNode *root)
{
  if (!root)
    return ans;
  getMinimumDifference(root->left);
  if (prev != -1)
    ans = min(ans, root->val - prev);
  prev = root->val;
  getMinimumDifference(root->right);
  return ans;
}
