Node *prev = NULL, *head = NULL;
Node *bToDLL(Node *root)
{
  // your code here
  if (!root)
    return NULL;
  convert(root);
  return head;
}

void convert(Node *root)
{
  if (!root)
    return;
  convert(root->left);
  if (prev == NULL)
    head = root;
  else
  {
    root->left = prev;
    prev->right = root;
  }
  prev = root;
  convert(root->right);
}