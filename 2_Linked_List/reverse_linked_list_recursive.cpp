struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseListRecursive(ListNode *head)
{
    // Base case: if the list is empty or has only one node
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Reverse the rest of the list
    ListNode *newHead = reverseListRecursive(head->next);

    // Append the current head at the end of the reversed list
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}
