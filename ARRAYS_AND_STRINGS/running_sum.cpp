#include <iostream>
#include <vector>

using namespace std;

vector<int> runningSum(vector<int> nums)
{
    vector<int> runningSum(nums.size());

    runningSum[0] = nums[0]; // here first elem will remain the same

    for (int i = 1; i < nums.size(); i++)
    {
        runningSum[i] = runningSum[i - 1] + nums[i]; // this will calc the running sum by adding curr elems
    }
    return runningSum;
}