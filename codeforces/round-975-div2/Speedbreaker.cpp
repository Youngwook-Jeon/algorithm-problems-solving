#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> mn(n + 1, n + 1), mx(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        mn[a[i]] = min(mn[a[i]], i);
        mx[a[i]] = max(mx[a[i]], i);
    }

    for (int i = 1; i <= n; i++)
    {
        mn[i] = min(mn[i], mn[i - 1]);
        mx[i] = max(mx[i], mx[i - 1]);
        if (mx[i] - mn[i] >= i)
        {
            cout << "0\n";
            return;
        }
    }

    int l = 0, r = n + 1;
    for (int i = 1; i <= n; i++)
    {
        l = max(l, i - a[i] + 1);
        r = min(r, i + a[i] - 1);
    }

    cout << r - l + 1 << '\n';
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
        solve(n);
    }
    return 0;
}