
TreeNode *mergeTrees(TreeNode *r1, TreeNode *r2)
{
  if (r1 && r2)
  {
    TreeNode *r = new TreeNode(r1->val + r2->val);
    r->left = mergeTrees(r1->left, r2->left);
    r->right = mergeTrees(r1->right, r2->right);
    return r;
  }
  return r1 ? r1 : r2;
}