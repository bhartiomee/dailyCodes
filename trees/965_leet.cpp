bool res = true;
bool isUnivalTree(TreeNode *root)
{
  traversal(root);
  return res;
}
TreeNode *traversal(TreeNode *root)
{
  if (root)
  {
    TreeNode *lst = traversal(root->left);
    TreeNode *rst = traversal(root->right);
    if (lst && root->val != lst->val)
      res = false;
    if (rst && root->val != rst->val)
      res = false;
    return root;
  }
  return NULL;
}