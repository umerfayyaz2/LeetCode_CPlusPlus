struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // If either list is empty, there is no intersection
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        // Initialize two pointers for both lists
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        // Traverse both lists
        while (ptrA != ptrB)
        {
            // Move to the next node or switch to the head of the other list
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }

        // Either they meet at the intersection or both are nullptr
        return ptrA;
    }
};