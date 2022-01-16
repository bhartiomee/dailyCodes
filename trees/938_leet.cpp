int sum = 0;
int rangeSumBST(TreeNode *root, int low, int high)
{
  if (!root)
    return 0;
  if (root->val >= low && root->val <= high)
    sum += root->val;
  int lst = rangeSumBST(root->left, low, high);
  int rst = rangeSumBST(root->right, low, high);
  return sum;
}