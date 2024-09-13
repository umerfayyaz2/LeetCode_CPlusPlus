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

        // The new head will be the second node
        ListNode *newHead = head->next;

        // Pointers to track current and next pair
        ListNode *prev = nullptr;
        ListNode *current = head;

        // Iterate while there are at least two nodes to swap
        while (current && current->next)
        {
            ListNode *nextPair = current->next->next; // Save the node after the pair
            ListNode *second = current->next;         // The second node in the current pair

            // Swap the current pair
            second->next = current;   // Point the second node to the first node
            current->next = nextPair; // Point the first node to the next pair

            // Connect the previous pair with the current swapped pair
            if (prev)
            {
                prev->next = second;
            }

            // Move pointers for the next swap
            prev = current;     // The current node becomes the previous node
            current = nextPair; // Move to the next pair
        }

        return newHead; // Return the new head, which is the second node
    }
};
