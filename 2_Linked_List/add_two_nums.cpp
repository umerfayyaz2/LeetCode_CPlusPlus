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
    ListNode *add_two_nums(ListNode *l1, ListNode *l2)
    {

        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;
        int carry = 0; // This will hold the carry value

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry > 0)
        {
            // Get the current values (if nodes exist)
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Compute the sum and the carry
            int sum = val1 + val2 + carry;
            carry = sum / 10; // Carry for the next addition in the next loop
            sum = sum % 10;   // The actual digit to store

            // Append the sum to the result list
            current->next = new ListNode(sum);
            current = current->next;

            // Move to the next nodes (if they exist)
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        // Return the next node of the dummy (this is the head of the result list)
        return dummy->next;
    }
};
