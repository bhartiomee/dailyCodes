Node *compute(Node *head)
{
    // your code goes here
    if (head == NULL || head->next == NULL)
        return head;
    Node *tmp = compute(head->next);
    if (head->data < tmp->data)
    {
        return tmp;
    }
    head->next = tmp;
    return head;
}
                                                                            
   