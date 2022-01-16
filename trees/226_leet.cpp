TreeNode *invertTree(TreeNode *root)
{
  if (root)
  {
    TreeNode *lst = invertTree(root->left);
    TreeNode *rst = invertTree(root->right);
    root->left = rst;
    root->right = lst;
    return root;
  }
  return NULL;
}