vector<int> nextLargerNodes(ListNode *head)
{
  ListNode *curr = head;
  stack<pair<int, int>> stk;
  vector<int> nge;
  int pos = 0;

  while (curr)
  {
    while (!stk.empty() && curr->val > (stk.top().first))
    {
      int idx = stk.top().second;
      nge[idx] = curr->val;
      stk.pop();
    }

    stk.push({curr->val, pos++});
    curr = curr->next;
    nge.push_back(0);
  }

  return nge;
}
