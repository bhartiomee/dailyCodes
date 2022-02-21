/*
INORDER:lst|root|rst
PREORDER:root|lst|rst

so leftmost of preorder is root for sure, find the idx of that elemt in inorder 0 to (idx-1)lst
idx+1 to n-1 rst
*/

int rootIdx = 0;
unordered_map<int, int> findPos;
Node *buildTree(int in[], int pre[], int n)
{
  // Code here
  for (int i = 0; i < n; i++)
    findPos[in[i]] = i;
  Node *root = construct(pre, 0, n - 1);
  return root;
}

Node *construct(int pre[], int start, int end)
{
  if (start > end)
    return nullptr;
  int num = pre[rootIdx];
  int idx = findPos[num];
  rootIdx++;
  Node *root = new Node(num);
  root->left = construct(pre, start, idx - 1);
  root->right = construct(pre, idx + 1, end);

  return root;
}

// post and ino
unordered_map<int, int> findPos;
int rootIdx;
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
  int n = postorder.size();
  rootIdx = n - 1;
  for (int i = 0; i < n; i++)
  {
    findPos[inorder[i]] = i;
  }
  return construct(postorder, 0, n - 1);
}

TreeNode *construct(vector<int> &post, int start, int end)
{
  if (start > end || rootIdx < 0)
    return nullptr;
  int num = post[rootIdx];
  int idx = findPos[num];
  TreeNode *root = new TreeNode(num);
  rootIdx--;

  root->right = construct(post, idx + 1, end);  //reverse postorder
  root->left = construct(post, start, idx - 1);
  return root;
}