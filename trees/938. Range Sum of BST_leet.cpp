//Approach 1;
int sum = 0;
int rangeSumBST(TreeNode *root, int low, int high)
{
  if (!root)
    return 0;

  if (root->val >= low && root->val <= high)
  {
    sum += root->val;
  }
  rangeSumBST(root->right, low, high);
  rangeSumBST(root->left, low, high);
  return sum;
}

//Aproach 2: Leveraging BST property, discarding useless brances;
int sum = 0;
int rangeSumBST(TreeNode *root, int low, int high)
{
  if (!root)
    return 0;
  traverse(root, low, high);
  return sum;
}
void traverse(TreeNode *root, int low, int high)
{
  if (!root)
    return;

  if (root->val >= low && root->val <= high)
  {
    sum += root->val;
  }
  if (root->val > low)
    traverse(root->left, low, high);
  if (root->val < high)
    traverse(root->right, low, high);
}