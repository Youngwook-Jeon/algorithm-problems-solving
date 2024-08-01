#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

bool check(vector<int> &arr, int n, int m, ll x)
{
    int cnt = 1;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > x)
        {
            sum = 0;
            cnt++;
        }
        sum += arr[i];
    }

    return cnt <= m;
}

int main()
{
    // code
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        ll lo = -1, hi = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            hi += arr[i];
            if (arr[i] > lo)
                lo = arr[i];
        }
        int m;
        cin >> m;

        if (n < m)
        {
            cout << -1 << '\n';
            continue;
        }

        while (lo < hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (check(arr, n, m, mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << hi << '\n';
    }
    return 0;
}