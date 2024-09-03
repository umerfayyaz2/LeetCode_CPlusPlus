#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_best_subarray(vector<int> &nums, int k)
{
    int current_sum = 0;

    // Calculate the sum of the first 'k' elements
    for (int i = 0; i < k; i++)
    {
        current_sum += nums[i];
    }

    int max_sum = current_sum;

    // Slide the window across the array
    for (int i = k; i < nums.size(); i++)
    {
        current_sum += nums[i] - nums[i - k];
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main()
{
    vector<int> nums = {1, 12, 16, 11, 9, -5, -6, 50, 3};
    int k = 4;

    int result = find_best_subarray(nums, k);
    cout << "The maximum sum of any subarray of size " << k << " is: " << result << endl;

    return 0;
}
