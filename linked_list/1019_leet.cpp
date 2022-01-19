vector<int> nextLargerNodes(ListNode *head)
{
  ListNode *curr = head;
  int n = 0;
  while (curr)
  {
    n++;
    curr = curr->next;
  }
  stack<pair<int, int>> stk;
  vector<int> nge(n, 0);
  int pos = 0;
  curr = head;
  stk.push({curr->val, pos});
  curr = head->next;
  while (curr)
  {
    while (!stk.empty() && curr->val > (stk.top().first))
    {
      int idx = stk.top().second;
      nge[idx] = curr->val;
      stk.pop();
    }
    pos++;
    stk.push({curr->val, pos});
    curr = curr->next;
  }
  return nge;
}
