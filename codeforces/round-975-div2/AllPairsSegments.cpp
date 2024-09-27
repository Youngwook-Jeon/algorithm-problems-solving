#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> x(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        map<ll, int> mp;
        for (int i = 1; i < n; i++)
        {
            int now = x[i];
            int next = x[i + 1];
            ll a = (ll)i * (n - i);
            mp[a] += (next - now - 1);

            ll b = (ll)i * (n - i + 1) - 1;
            mp[b] += 1;
        }
        mp[n - 1] += 1;

        for (int i = 0; i < q; i++)
        {
            ll query;
            cin >> query;
            cout << mp[query] << ' ';
        }
        cout << '\n';
    }
    return 0;
}