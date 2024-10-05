#include <iostream>
using namespace std;
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
    ListNode *insertionSortList(ListNode *head)
    {
        // Create a dummy node that acts as a placeholder for the sorted part
        ListNode *dummy = new ListNode(0); // The dummy node simplifies insertion at the head
        ListNode *current = head;          // Current node to be inserted

        while (current != nullptr)
        {
            ListNode *prev = dummy;             // Start from the beginning of the sorted part
            ListNode *nextNode = current->next; // Save the next node to process after insertion

            // Find the position where to insert the current node in the sorted list
            while (prev->next != nullptr && prev->next->val < current->val)
            {
                prev = prev->next;
            }

            // Insert the current node between prev and prev->next
            current->next = prev->next;
            prev->next = current;

            // Move to the next node in the unsorted part
            current = nextNode;
        }

        // The dummy node's next points to the head of the sorted list
        return dummy->next;
    }

    // Helper function to print a linked list
    void printList(ListNode *head)
    {
        while (head != nullptr)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};