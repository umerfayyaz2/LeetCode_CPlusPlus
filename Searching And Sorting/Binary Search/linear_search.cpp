#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{

    for (int i = 0; i < n; i++)
    {
        // If element is found, return the index
        if (arr[i] == x)
        {
            return i;
        }
    }
    // If element is not found, return -1
    return -1;
}

int main()
{
    int n = 4;
    int arr[] = {1, 2, 3, 4};
    int x = 3;

    int result = search(arr, n, x);
    cout << "Output: " << result << endl;

    int arr2[] = {1, 2, 3, 4, 5};
    int x2 = 5;
    int result2 = search(arr2, 5, x2);
    cout << "Output: " << result2 << endl;

    return 0;
}
