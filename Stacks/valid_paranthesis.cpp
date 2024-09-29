#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

bool isValid(string s)
{
    stack<char> bracketStack;
    unordered_map<char, char> matchingBrackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}};

    for (char c : s)
    {
        // If c is a closing bracket
        if (matchingBrackets.count(c))
        {
            // Check if the stack is not empty and the top matches the corresponding open bracket
            if (!bracketStack.empty() && bracketStack.top() == matchingBrackets[c])
            {
                bracketStack.pop();
            }
            else
            {
                return false; // No matching open bracket or stack is empty
            }
        }
        else
        {
            // If it's an opening bracket, push it to the stack
            bracketStack.push(c);
        }
    }

    // If stack is empty, all brackets were matched correctly
    return bracketStack.empty();
}
