//BST
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
  int small = min(p->val, q->val);
  int larger = max(p->val, q->val);
  if (!root)
    return nullptr;
  if (root->val > larger)
    return lowestCommonAncestor(root->left, p, q);
  if (root->val < small)
    return lowestCommonAncestor(root->right, p, q);
  return root;
}

//BT

//Approach 1:
TreeNode *ans;
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
  if (!root || root == p || root == q)
    return root;
  TreeNode *lst = lowestCommonAncestor(root->left, p, q);
  TreeNode *rst = lowestCommonAncestor(root->right, p, q);
  if (lst && rst)
    return root;
  if (!lst)
    return rst;
  return lst;
}

//Approach 2:
TreeNode *ans;
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
  lca(root, p, q);
  return ans;
}
bool lca(TreeNode *root, TreeNode *p, TreeNode *q)
{
  if (!root)
    return false;
  bool lst = lca(root->left, p, q);
  bool rst = lca(root->right, p, q);

  bool tmp = (root == p || root == q);
  if (tmp && rst || tmp && lst || lst && rst)
    ans = root;
  return (tmp || lst || rst);
}