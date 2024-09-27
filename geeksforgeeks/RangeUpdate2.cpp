#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void propagate(int node, int s, int e, vector<ll> &st, vector<ll> &lazy, vector<bool> &isLazy)
{
    if (isLazy[node])
    {
        st[node] |= lazy[node];
        if (s != e)
        {
            isLazy[2 * node] = true;
            isLazy[2 * node + 1] = true;
            lazy[2 * node] |= lazy[node];
            lazy[2 * node + 1] |= lazy[node];
        }
        lazy[node] = 0;
        isLazy[node] = false;
    }
}

void update_range(int node, int s, int e, int l, int r, ll val, vector<ll> &st, vector<ll> &lazy, vector<bool> &isLazy)
{
    propagate(node, s, e, st, lazy, isLazy);

    if (s > r || e < l)
        return;

    if (l <= s && e <= r)
    {
        isLazy[node] = true;
        lazy[node] = val;
        propagate(node, s, e, st, lazy, isLazy);
        return;
    }

    int m = (s + e) / 2;
    update_range(2 * node, s, m, l, r, val, st, lazy, isLazy);
    update_range(2 * node + 1, m + 1, e, l, r, val, st, lazy, isLazy);
    st[node] = st[2 * node] & st[2 * node + 1];
}

ll query(int node, int s, int e, int l, int r, vector<ll> &st, vector<ll> &lazy, vector<bool> &isLazy)
{
    propagate(node, s, e, st, lazy, isLazy);

    if (s > r || e < l)
        return -1;

    if (l <= s && e <= r)
    {
        return st[node];
    }

    int m = (s + e) / 2;
    return query(2 * node, s, m, l, r, st, lazy, isLazy) & query(2 * node + 1, m + 1, e, l, r, st, lazy, isLazy);
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
        int n, q;
        cin >> n >> q;
        vector<ll> st(4 * n);
        vector<ll> lazy(4 * n, 0);
        vector<bool> isLazy(4 * n, false);

        for (int i = 0; i < q; i++)
        {
            int cm;
            cin >> cm;
            if (cm == 1)
            {
                int l, r;
                ll v;
                cin >> l >> r >> v;
                --l;
                --r;
                update_range(1, 0, n - 1, l, r, v, st, lazy, isLazy);
            }
            else
            {
                int l, r;
                cin >> l >> r;
                --l;
                --r;
                ll ans = query(1, 0, n - 1, l, r, st, lazy, isLazy);
                cout << ans << '\n';
            }
        }
    }
    return 0;
}