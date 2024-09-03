#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int window_max_length_finder(vector<int> nums, int target_sum)
{
    int left_index = 0;
    int current_sum = 0;
    int max_length = 0;

    for (int right_index = 0; right_index < nums.size(); right_index++)
    {
        current_sum += nums[right_index]; // will add the curr elem to the sub-araray / window

        while (current_sum > target_sum) // if the current_sum  is greater than target_sum
        {
            current_sum -= nums[left_index]; // remove the elem at left pos
            left_index++;                    // move left index to right
        }

        max_length = max(max_length, right_index - left_index + 1);
    }

    return max_length;
}

int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int k = 7;

    int result = window_max_length_finder(nums, k);
    cout << "The maximum length of subarray with sum <= " << k << " is: " << result << endl;

    return 0;
}