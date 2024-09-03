#include <iostream>
#include <vector>

using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    // Starting the second element and update each element to be the running sum
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] += nums[i - 1]; // Add the previous elem's value to the current element
    }

    return nums; // Return the modified nums array
}