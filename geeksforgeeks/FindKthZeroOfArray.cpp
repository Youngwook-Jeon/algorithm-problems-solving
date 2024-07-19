#include <iostream>
using namespace std;
// a: a given array consisted by only 0 and 1.

int ask(int l, int h)
{
    cout << "? " << l << ' ' << h << endl;
    int s;
    cin >> s;
    return s;
}

void findKthZero(int n, int k)
{
    int l = 1, h = n; // 1-based index
    while (l < h)
    {
        int mid = (l + h) / 2;
        int ones = ask(1, mid);
        int zeros = mid - ones;
        if (zeros >= k)
        {
            h = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << "! " << h << endl;
}