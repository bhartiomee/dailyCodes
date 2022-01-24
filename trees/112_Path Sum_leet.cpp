// Solution 1
bool flag = false;
bool hasPathSum(TreeNode *root, int targetSum)
{
  if (!root)
    return false;
  traverse(root, targetSum, 0);
  return flag;
}
void traverse(TreeNode *root, int targetSum, int sum)
{
  if (!root)
    return;
  if (!root->left && !root->right)
  {
    sum += root->val;
    if (sum == targetSum)
      flag = true;
    return;
  }

  traverse(root->left, targetSum, sum + root->val);
  traverse(root->right, targetSum, sum + root->val);
}

// Solution 2
bool hasPathSum(TreeNode *root, int targetSum)
{
  if (!root)
    return false;
  targetSum -= root->val;
  if (targetSum == 0 && !root->left && !root->right)
    return true;
  return hasPathSum(root->left, targetSum) ||
         hasPathSum(root->right, targetSum);
}