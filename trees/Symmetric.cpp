bool isSymmetric(TreeNode *root)
{
  if (!root)
    return true;
  return isMirror(root->left, root->right);
}
bool isMirror(TreeNode *r1, TreeNode *r2)
{
  if (!r1 && !r2)
    return true;
  if (!r1 || !r2)
    return false;
  return r1->val == r2->val &&
         isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
}