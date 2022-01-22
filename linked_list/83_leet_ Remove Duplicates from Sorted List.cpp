/*Q:- Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter 
in pattern and a non-empty word in s.
*/
ListNode *deleteDuplicates(ListNode *head)
{
  if (!head)
    return nullptr;
  ListNode *curr = head->next;
  ListNode *prev = head;
  while (curr)
  {
    while (curr && curr->val == prev->val)
    {
      curr = curr->next;
    }
    prev->next = curr;
    if (curr)
    {
      prev = curr;
      curr = curr->next;
    }
  }
  return head;
}