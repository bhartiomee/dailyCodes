ListNode *reverseKGroup(ListNode *head, int k)
{
  if (!head || k == 1)
    return head;
  ListNode *curr = head;
  int cnt = 0;
  while (curr)
  {
    cnt++;
    curr = curr->next;
  }
  if (cnt < k)
    return head;
  ListNode *tmp, *prev;
  prev = NULL;
  curr = head;
  cnt = 0;
  while (curr && cnt < k)
  {
    tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
    cnt++;
  }
  if (curr)
    head->next = reverseKGroup(curr, k);
  return prev;
}