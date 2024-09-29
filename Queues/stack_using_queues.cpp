#include <queue>
#include <iostream>
using namespace std;

class MyStack
{
private:
    queue<int> q1; // Primary queue to hold elements
    queue<int> q2; // Secondary queue used for pop and top operations

public:
    // Constructor
    MyStack() {}

    // Push element x onto stack
    void push(int x)
    {
        q1.push(x);
    }

    // Removes the element on the top of the stack and returns it
    int pop()
    {
        // Move all elements except the last one to q2
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        // Get the last element which is the top of the stack
        int top_element = q1.front();
        q1.pop(); // Remove the top element

        // Swap q1 and q2
        swap(q1, q2);

        return top_element;
    }

    // Get the top element
    int top()
    {
        // Similar to pop but don't remove the last element
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        // Get the last element which is the top of the stack
        int top_element = q1.front();

        // Move the top element to q2 to maintain stack order
        q2.push(top_element);
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);

        return top_element;
    }

    // Returns whether the stack is empty
    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top element: " << stack.top() << endl;                       // Should print 3
    cout << "Popped element: " << stack.pop() << endl;                    // Should print 3
    cout << "Top element: " << stack.top() << endl;                       // Should print 2
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Should print No

    return 0;
}
