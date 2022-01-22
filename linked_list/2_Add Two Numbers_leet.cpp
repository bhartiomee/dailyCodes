ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

  int carry = 0;
  ListNode *ans = new ListNode(-1);
  ListNode *ansHead = ans;
  while (l1 || l2)
  {
    int n1 = (l1) ? l1->val : 0;
    int n2 = (l2) ? l2->val : 0;
    int s = carry + n1 + n2;
    carry = s / 10;
    ListNode *tmp = new ListNode(s % 10);
    if (ans->val == -1)
    {
      ans = tmp;
      ansHead = ans;
    }
    else
    {
      ans->next = tmp;
      ans = tmp;
    }
    if (l1)
      l1 = l1->next;
    if (l2)
      l2 = l2->next;
  }
  if (carry > 0)
    ans->next = new ListNode(carry);
  return ansHead;
}