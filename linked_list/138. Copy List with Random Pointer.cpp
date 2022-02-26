/*
create new node for every node in original LL nad store them in a map
then travel the old list again and loction the connection of new list accodinlgy.
Spac:O(N)
Time:O(N)
*/

/*
The idea is to merge the old and new list(while we create it)
We create a new node like in prevoius method and attach it to original curr->next and and the old curr->next is now new node->next.
so say any node 'a' for old list will correspond to a->next for new list.
Space-O(1)
Time-O(N)
*/
Node *copyRandomList(Node *head)
{
  if (!head)
    return NULL;
  Node *curr = head;
  Node *cloneHead = NULL;
  Node *tmp;
  while (curr)
  {
    Node *node = new Node(curr->val);
    if (cloneHead == NULL)
      cloneHead = node;
    tmp = curr->next;
    curr->next = node;
    node->next = tmp;
    curr = tmp;
  }
  curr = head;
  while (curr)
  {
    if (curr->random)
      curr->next->random = curr->random->next;
    else
      curr->next->random = NULL;
    curr = curr->next->next;
  }

  Node *cloneCurr = cloneHead;
  curr = head;
  while (cloneCurr && cloneCurr->next)
  {
    tmp = cloneCurr->next;
    cloneCurr->next = cloneCurr->next->next;
    cloneCurr = cloneCurr->next;
    curr->next = tmp;
    curr = curr->next;
  }
  if (curr)
    curr->next = NULL;
  return cloneHead;
}
