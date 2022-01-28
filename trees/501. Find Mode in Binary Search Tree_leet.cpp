/*
Approach:
as inorderof BST will give sorted order values, so track the prev value,if the root==prev then increment the freq
but if it not set freq=1
now as we want to find maximum occuring node, so e track max frequecy till now ,
if we get curr frequency that is greater than max frequency that means that the pervoius values are of no use and discard them, ans set maxFreq=currFreq
and if we ge values of freq==maxFreq, that is too a valid anser and include it
*/
vector<int> ans;
int currFreq = 0;
int maxFreq = 0;
int prev;
vector<int> findMode(TreeNode *root)
{
  inorder(root);
  return ans;
}
void inorder(TreeNode *root)
{
  if (!root)
    return;
  inorder(root->right);
  if (prev == root->val)
    currFreq++;
  else
    currFreq = 1;
  if (currFreq > maxFreq)
  {
    ans.clear();
    maxFreq = currFreq;
    ans.push_back(root->val);
  }
  else if (currFreq == maxFreq)
    ans.push_back(root->val);
  prev = root->val;
  inorder(root->left);
}
