#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int i, ll sum, ll mx, ll k)
{
    ll need = mx * i - sum;
    if (need <= 0)
    {
        return (sum % i == 0) || (i - sum % i <= k);
    }
    return need <= k;
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
        int n, ans;
        ll k;
        ll sum = 0, mx = 0;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            mx = max(mx, a[i]);
        }

        for (int i = n; i >= 1; i--)
        {
            if (check(i, sum, mx, k))
            {
                ans = i;
                break;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}