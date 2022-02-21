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