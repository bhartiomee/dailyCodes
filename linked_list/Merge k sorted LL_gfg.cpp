Node *mergeKLists(Node *arr[], int k)
{
  // Your code here
  if (k == 1)
    return arr[0];
  Node *curr = merge(arr[0], arr[1]);
  int i = 2;
  while (i < k)
  {
    curr = merge(curr, arr[i]);
    i++;
  }
  return curr;
}
Node *merge(Node *l, Node *r)
{
  Node *head = new Node(0);
  Node *tmp = head;

  while (l && r)
  {
    if (l->data < r->data)
    {
      tmp->next = l;
      tmp = tmp->next;
      l = l->next;
    }
    else
    {
      tmp->next = r;
      tmp = tmp->next;
      r = r->next;
    }
  }
  if (!r)
    tmp->next = l;
  else
    tmp->next = r;
  return head->next;
}