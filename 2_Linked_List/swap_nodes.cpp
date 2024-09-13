struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // Edge case: if the list is empty or has only one node, return head
        if (!head || !head->next)
            return head;

        // Create a dummy node to simplify swapping logic at the head
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        // Pointer to the node before the current pair
        ListNode *prev = dummy;

        // Iterate through the list while there are pairs to swap
        while (prev->next && prev->next->next)
        {
            // Identify the two nodes to swap
            ListNode *first = prev->next;
            ListNode *second = first->next;

            // Perform the swap
            first->next = second->next; // Link first node to the next of second
            second->next = first;       // Link second node to first
            prev->next = second;        // Link prev to second (new head of this pair)

            // Move the prev pointer to the end of the swapped pair
            prev = first; // first is now after second
        }

        // Return the new head (the second node of the original list)
        return dummy->next;
    }
};
