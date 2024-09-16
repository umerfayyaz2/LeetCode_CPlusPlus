#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> result(k, nullptr);

        // Step 1: Find the length of the linked list
        int listLength = 0;
        ListNode *temp = head;
        while (temp)
        {
            listLength++;
            temp = temp->next;
        }

        // Step 2: Calculate the size of each part
        int baseSize = listLength / k;   // Minimum size for each part
        int extraNodes = listLength % k; // Extra nodes to distribute to the first parts

        // Step 3: Split the linked list
        ListNode *current = head;
        for (int i = 0; i < k; i++)
        {
            // Set the head of the current part
            result[i] = current;
            int currentPartSize = baseSize + (extraNodes > 0 ? 1 : 0);
            extraNodes--;

            // Move the current pointer to the end of the current part
            for (int j = 0; j < currentPartSize - 1; j++)
            {
                if (current)
                    current = current->next;
            }

            // Cut the current part from the next
            if (current)
            {
                ListNode *nextPart = current->next;
                current->next = nullptr;
                current = nextPart;
            }
        }

        return result;
    }
};
