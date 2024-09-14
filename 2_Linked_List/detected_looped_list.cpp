struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Function to detect a loop in the linked list
int detectLoop(Node *head)
{
    // Initialize two pointers, slow and fast
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // Move slow pointer by 1 step
        fast = fast->next->next; // Move fast pointer by 2 steps

        // If slow and fast meet, there is a loop
        if (slow == fast)
        {
            return 1; // Loop detected
        }
    }

    return 0; // No loop detected
}

// Helper function to create a loop in the linked list
void createLoop(Node *head, int x)
{
    if (x == 0)
        return; // No loop
    Node *temp = head;
    Node *loopNode = nullptr;
    int count = 1;

    // Traverse to the x-th node (where loop starts)
    while (temp->next != nullptr)
    {
        if (count == x)
        {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }

    // Create a loop by connecting the last node to the x-th node
    if (loopNode != nullptr)
    {
        temp->next = loopNode;
    }
}