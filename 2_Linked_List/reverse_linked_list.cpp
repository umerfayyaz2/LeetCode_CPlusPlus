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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;

        while (current != nullptr)
        {
            ListNode *nextNode = current->next; // Save the next node
            current->next = prev;               // Reverse the current node's pointer
            prev = current;                     // Move prev to the current node
            current = nextNode;                 // Move to the next node
        }

        return prev; // Prev is the new head of the reversed list
    }
};