
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *remove_taget_elems(ListNode *head, int val)
    {
        // Step 1: Create a dummy node
        ListNode *dummy = new ListNode(-1); // Create a dummy node with arbitrary value
        dummy->next = head;                 // Point dummy's next to the original head

        // Step 2: Initialize pointers
        ListNode *current = dummy; // Start from the dummy node

        // Step 3: Traverse the list
        while (current->next != nullptr)
        {
            if (current->next->val == val)
            {
                // Remove the node with value 'val' by skipping it
                current->next = current->next->next;
            }
            else
            {
                // Move to the next node
                current = current->next;
            }
        }

        // Step 4: Return the updated list starting after the dummy node
        return dummy->next;
    }
};