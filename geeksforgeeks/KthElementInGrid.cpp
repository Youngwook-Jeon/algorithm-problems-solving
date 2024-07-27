#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

bool check(vector<ll> &a, vector<ll> &b, int n, int k, ll cur)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += upper_bound(b.begin(), b.end(), cur / a[i]) - b.begin();
    }

    return cnt >= k;
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
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        vector<ll> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        sort(b.begin(), b.end());

        ll lo = 1, hi = 1e18;
        while (lo < hi)
        {
            ll mid = (lo + hi) / 2;
            if (check(a, b, n, k, mid))
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