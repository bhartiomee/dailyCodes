ListNode *sortList(ListNode *head)
{
  if (!head || !head->next)
    return head;

  ListNode *slow = head;
  ListNode *fast = head->next->next;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  ListNode *r = sortList(slow->next);
  slow->next = NULL;
  ListNode *l = sortList(head);
  return merge(l, r);
}

ListNode *merge(ListNode *first, ListNode *second)
{
  ListNode *ans = new ListNode(0);
  ListNode *curr = ans;
  while (first && second)
  {
    if (first->val < second->val)
    {
      curr->next = first;
      first = first->next;
    }
    else
    {
      curr->next = second;
      second = second->next;
    }
    curr = curr->next;
  }
  if (first)
    curr->next = first;
  else
    curr->next = second;

  return ans->next;
}
