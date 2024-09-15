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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even; // Store the start of the even list

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next; // Link odd node to the next odd node
            odd = odd->next;        // Move odd pointer forward

            even->next = odd->next; // Link even node to the next even node
            even = even->next;      // Move even pointer forward
        }

        // After separating odd and even, link odd's last node to even's head
        odd->next = evenHead;

        return head;
    }
};