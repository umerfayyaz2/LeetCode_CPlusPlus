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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
        {
            return nullptr;
        }

        // Step 1: Detect if there's a cycle using slow and fast pointers.
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // slow moves 1 step
            fast = fast->next->next; // fast moves 2 steps

            if (slow == fast)
            {
                // Step 2: Reset one pointer to the head.
                slow = head;

                // Step 3: Move both slow and fast one step at a time.
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                // Both pointers meet at the start of the cycle.
                return slow;
            }
        }

        // No cycle detected.
        return nullptr;
    }
};