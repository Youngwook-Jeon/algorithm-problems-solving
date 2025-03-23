#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;

#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define forEachTestCase    \
    long long numTestCase; \
    cin >> numTestCase;    \
    while (numTestCase--)
#define newl '\n'

void use_file_input_output()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int sa = n - 1, sb = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (a[sa] >= b[sb] || k == 0)
        {
            ans += a[sa];
            sa--;
        }
        else
        {
            ans += b[sb];
            sb--;
            k--;
        }
    }

    cout << ans << newl;
}

int main()
{
    FASTIO
    forEachTestCase solve();
    return 0;
}
