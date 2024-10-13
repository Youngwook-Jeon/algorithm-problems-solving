#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1E-9;

bool check(ll mid, ll sum, vector<int> &vi)
{
    int cnt = 0, n = vi.size();
    double avg = ((double)sum + mid) / (2 * n);
    for (int i = 0; i < n; i++)
    {
        if ((double)vi[i] < avg)
            cnt++;
    }

    if (cnt > n / 2)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vi(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> vi[i];
            sum += vi[i];
        }

        if (n <= 2)
        {
            cout << "-1" << '\n';
            continue;
        }

        sort(vi.begin(), vi.end());

        ll lo = 0, hi = (ll)2 * n * vi[n - 1];
        while (lo < hi)
        {
            ll mid = (lo + hi) / 2;
            if (check(mid, sum, vi))
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