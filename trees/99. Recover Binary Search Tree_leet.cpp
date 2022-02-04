TreeNode *first = nullptr, *second = nullptr;
TreeNode *prev = new TreeNode(INT_MIN);
void recoverTree(TreeNode *root)
{
  if (!root)
    return;
  inorder(root);
  int tmp = first->val;
  first->val = second->val;
  second->val = tmp;
}

void inorder(TreeNode *root)
{
  if (!root)
    return;
  inorder(root->left);
  if (first == NULL && prev->val > root->val)
    first = prev;
  if (first != NULL && prev->val > root->val)
  {
    second = root;
  }
  prev = root;
  inorder(root->right);
}
