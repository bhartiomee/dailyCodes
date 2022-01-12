// https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  TreeNode *insertIntoBST(TreeNode *root, int val)
  {
    if (!root)
    {
      TreeNode *n = new TreeNode(val);
      return n;
    }

    if (val > root->val)
      root->right = insertIntoBST(root->right, val);
    else
      root->left = insertIntoBST(root->left, val);
    return root;
  }
};
//
TreeNode *insertIntoBST(TreeNode *root, int val)
{
  if (!root)
    return new TreeNode(val);
  TreeNode *cur = root;
  while (cur)
  {
    if (val > cur->val)
    {
      if (cur->right)
        cur = cur->right;
      else
      {
        cur->right = new TreeNode(val);
        break;
      }
    }
    else
    {
      if (cur->left)
        cur = cur->left;
      else
      {
        cur->left = new TreeNode(val);
        break;
      }
    }
  }
  return root;
}
