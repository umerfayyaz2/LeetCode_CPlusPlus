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
    ListNode *merge_two_lists(ListNode *list1, ListNode *list2)
    {

        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                current->next = list1; // Append list1's node
                list1 = list1->next;   // Move list1's pointer forward
            }
            else
            {
                current->next = list2; // Append list2's node
                list2 = list2->next;   // Move list2's pointer forward
            }
            current = current->next; // Move the current pointer forward
        }

        // Attach the remaining nodes of list1 or list2 until exhausted (if any)
        if (list1 != nullptr)
        {
            current->next = list1;
        }
        else if (list2 != nullptr)
        {
            current->next = list2;
        }

        // The merged list starts after the dummy node , this will act as head
        return dummy->next;
    }
};