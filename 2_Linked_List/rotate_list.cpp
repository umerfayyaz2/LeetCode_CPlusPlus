struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        // Edge cases
        if (!head || !head->next || k == 0)
        {
            return head;
        }

        // Step 1: Find the length of the list and the last node
        ListNode *old_tail = head;
        int length = 1; // Start with 1 because we already have head

        while (old_tail->next != nullptr)
        {
            old_tail = old_tail->next;
            length++;
        }

        // Step 2: Compute the effective rotation
        k = k % length;
        if (k == 0)
            return head; // No rotation needed

        // Step 3: Find the new tail (length - k - 1) and new head (length - k)
        ListNode *new_tail = head;
        for (int i = 1; i < length - k; ++i)
        {
            new_tail = new_tail->next;
        }

        // Step 4: Perform the rotation
        ListNode *new_head = new_tail->next;
        old_tail->next = head;    // Connect the old tail to the head
        new_tail->next = nullptr; // New tail should point to nullptr

        return new_head;
    }
};
