int pairSum(ListNode *head)
{
  ListNode *slow = head;
  ListNode *fast = head;
  ListNode *prev = NULL;

  //slow fast pointer to get the mid of the list
  while (fast && fast->next)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = nullptr;               // make next the node before slow to null so we get two different lists
  ListNode *lastCurr = reverse(slow); //reverse from mid

  ListNode *curr = head; //pointer that will traverse from start
  int ans = 0;
  //simple two pointer, curr will move from begining and lastCurr from end , add the val and trace the max
  while (curr && lastCurr)
  {
    ans = max(ans, curr->val + lastCurr->val);
    curr = curr->next;
    lastCurr = lastCurr->next;
  }
  return ans;
}
//function to reverse the linked list
ListNode *reverse(ListNode *head)
{
  ListNode *prev = NULL;
  ListNode *curr = head;
  while (curr)
  {
    ListNode *tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }
  return prev;
}