#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If we found the target, return its index
        if (nums[mid] == target)
        {
            return mid;
        }

        // Check if the left half is sorted
        if (nums[low] <= nums[mid])
        {
            // If the target is within the range of the sorted left half
            if (target >= nums[low] && target < nums[mid])
            {
                high = mid - 1; // Search in the left half
            }
            else
            {
                low = mid + 1; // Search in the right half
            }
        }
        // Otherwise, the right half must be sorted
        else
        {
            // If the target is within the range of the sorted right half
            if (target > nums[mid] && target <= nums[high])
            {
                low = mid + 1; // Search in the right half
            }
            else
            {
                high = mid - 1; // Search in the left half
            }
        }
    }

    // If we exit the loop, the target was not found
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = search(nums, target);
    cout << "Index of target " << target << " is: " << result << endl;

    target = 3;
    result = search(nums, target);
    cout << "Index of target " << target << " is: " << result << endl;

    return 0;
}
