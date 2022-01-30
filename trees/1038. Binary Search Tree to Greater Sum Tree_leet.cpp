int prev;
TreeNode *bstToGst(TreeNode *root)
{
  if (!root)
    return nullptr;
  if (root->right)
    bstToGst(root->right);
  root->val += prev;
  prev = root->val;
  if (root->left)
    bstToGst(root->left);

  return root;
}