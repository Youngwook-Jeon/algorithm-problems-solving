#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<ll, ll> mp;
    mp[0] = 1;
    int ans = 1;
    ll acc = 0LL, all = 1LL;

    for (int i = 0; i < n; i++)
    {
        acc += v[i];
        ll ban = acc - k;
        ans = (all - mp[ban]) % MOD;
        mp[acc] += ans;
        all += ans;
    }

    cout << ans << '\n';

    return 0;
}