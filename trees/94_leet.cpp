vector<int> inorderResult;
vector<int> inorderTraversal(TreeNode *root)
{
  inorder(root);
  return inorderResult;
}
void inorder(TreeNode *root)
{
  if (!root)
    return;
  inorder(root->left);
  inorderResult.push_back(root->val);
  inorder(root->right);
}