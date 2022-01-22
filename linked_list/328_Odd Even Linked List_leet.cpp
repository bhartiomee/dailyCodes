ListNode *oddEvenList(ListNode *head)
{
    if (!head)
        return nullptr;
    if (!head->next)
        return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evHead = even;
    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evHead;
    return head;
}