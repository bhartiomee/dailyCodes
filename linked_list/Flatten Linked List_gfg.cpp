Node *flatten(Node *root)
{
  // Your code here
  Node *curr = root;
  while (curr)
  {
    Node *tmp = curr->next;
    curr->next = nullptr;
    while (curr->bottom)
    {
      curr->next = curr->bottom;
      curr = curr->next;
    }
    curr->bottom = tmp;
    curr = curr->bottom;
  }

  for (auto i = root; i != nullptr; i = i->bottom)
  {
    for (auto j = i->bottom; j != nullptr; j = j->bottom)
    {
      if (i->data > j->data)
      {
        int tmp = i->data;
        i->data = j->data;
        j->data = tmp;
      }
    }
  }
  return root;
}