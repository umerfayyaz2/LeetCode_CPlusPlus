#include <queue>
#include <iostream>
using namespace std;

class RecentCounter
{
private:
    queue<int> requestQueue;

public:
    RecentCounter()
    {
        // Initialize an empty queue.
    }

    int ping(int t)
    {
        // Add the new request time t to the queue.
        requestQueue.push(t);

        // Remove all requests that occurred more than 3000 milliseconds ago.
        while (requestQueue.front() < t - 3000)
        {
            requestQueue.pop();
        }

        // The size of the queue now is the number of requests in the range [t-3000, t].
        return requestQueue.size();
    }
};

int main()
{
    RecentCounter rc;
    cout << rc.ping(1) << endl; // Example usage
    cout << rc.ping(100) << endl;
    cout << rc.ping(3001) << endl;
    cout << rc.ping(3002) << endl;

    return 0;
}
