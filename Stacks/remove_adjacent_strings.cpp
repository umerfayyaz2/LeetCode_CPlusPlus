#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> stack;

        // Traverse each character in the string
        for (char c : s)
        {
            // If the stack is not empty and the top of the stack is equal to the current character
            if (!stack.empty() && stack.top() == c)
            {
                stack.pop(); // Remove the duplicate
            }
            else
            {
                stack.push(c); // Push the character onto the stack
            }
        }

        // Build the final string from the stack
        string result;
        while (!stack.empty())
        {
            result += stack.top();
            stack.pop();
        }

        // Since the stack holds characters in reverse order, we reverse the result
        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    Solution solution;
    string input = "abbaca";
    string output = solution.removeDuplicates(input);
    cout << "Result after removing duplicates: " << output << endl;
    return 0;
}
