#include <algorithm>
using namespace std;

// a: a given array
// n: the length of a
// k: a given maximum cost to perform the operation
// You can perform an operation on an array that increases the value at any chosen index by 1.
// Find the max median of the array.
int cost(int m, int n, int a[])
{
    int ans = 0;
    for (int i = n / 2; i < n; i++)
    {
        ans += max(0, m - a[i]);
    }

    return ans;
}

int maxMedian(int n, int k, int a[])
{
    sort(a, a + n);

    int l = a[n / 2], h = a[n / 2] + k;
    while (l < h)
    {
        int mid = (l + h + 1) / 2;
        if (cost(mid, n, a) <= k)
        {
            l = mid;
        }
        else
        {
            h = mid - 1;
        }
    }

    return l;
}
