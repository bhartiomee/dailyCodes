int maxm;
int diameterOfBinaryTree(TreeNode *root)
{
  if (!root)
    return 0;
  int lst = getHt(root->left);
  int rst = getHt(root->right);
  maxm = max(maxm, lst + rst); //as the diameter will not alwyas pass through the root
  diameterOfBinaryTree(root->left);
  diameterOfBinaryTree(root->right);
  return maxm;
}
int getHt(TreeNode *root)
{
  if (!root)
    return 0;
  return 1 + max(getHt(root->right), getHt(root->left));
}
