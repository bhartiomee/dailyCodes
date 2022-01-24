//Approch 1:(naive)
//space:O(M);
//Time=O(M+N);
//MOre brute force could be to check node of l1 for every node of l2 and mathc them ,constant space and O(M*N);
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
  unordered_set<ListNode *> hashset;
  ListNode *h1, *h2;
  h1 = headA;
  h2 = headB;

  while (h1)
  {
    hashset.insert(h1);
    h1 = h1->next;
  }

  ListNode *ans = NULL;
  while (h2 && ans == NULL)
  {
    if (hashset.find(h2) != hashset.end())
      ans = h2;
    h2 = h2->next;
  }
  return ans;
}

//Approch 2
//Space:O(1) Time:-O(M+N)
/**
 * Find the length of l1 and l2 and then their abs diff (d)
 * move the pointer of longer list by 'd' nodes and , keep shorter at head node
 * start traversing and then they would meet at the intersection point
 * */

//Approach 3:(Intutive)
//Space:O(1) Time:O(M)

//It also works same as approach 2 works.
/**
 * If length(l1)<length(l2), and both started movig from their head, by the time h1 reaches end of the list 
 * h2 will be behind by (l2-l1), so when h1 becomes null we point h1 to headB, then by the time h2 reaches the end
 * h1 would have covered (l2-l2) in list2.
 * And then when h2 will start from headA, that wll be the exact position of Approach 2(second point)
 **/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{

  ListNode *h1, *h2;
  h1 = headA;
  h2 = headB;

  while (h1 != h2)
  {
    h1 = h1 ? h1->next : headB;
    h2 = h2 ? h2->next : headA;
  }
  return h1;
}
