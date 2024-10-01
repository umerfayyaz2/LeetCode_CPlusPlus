#include <iostream>
using namespace std;

int mySqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x; // Handle cases where x is 0 or 1.
    }

    int low = 0, high = x, result = 0;

    // Binary Search
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check if mid*mid is equal to x
        if (mid <= x / mid)
        {                  // Same as checking mid*mid <= x to prevent overflow
            result = mid;  // mid is a candidate for the result
            low = mid + 1; // Search in the higher half
        }
        else
        {
            high = mid - 1; // Search in the lower half
        }
    }

    return result;
}

int main()
{
    int x = 8;
    cout << "Square root of " << x << " is " << mySqrt(x) << endl;

    x = 4;
    cout << "Square root of " << x << " is " << mySqrt(x) << endl;

    return 0;
}
