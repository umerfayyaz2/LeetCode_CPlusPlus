#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> answer(n, 0); // Initialize answer array with 0
    stack<int> tempStack;     // Stack to store indices of temperatures

    // Traverse the temperature array
    for (int i = 0; i < n; ++i)
    {
        // While the stack is not empty and the current temperature is greater than
        // the temperature at the index on the top of the stack
        while (!tempStack.empty() && temperatures[i] > temperatures[tempStack.top()])
        {
            int prevDay = tempStack.top(); // Index of the previous day
            tempStack.pop();
            answer[prevDay] = i - prevDay; // Calculate the difference in days
        }
        tempStack.push(i); // Push current day's index onto the stack
    }

    return answer; // Return the answer array
}
