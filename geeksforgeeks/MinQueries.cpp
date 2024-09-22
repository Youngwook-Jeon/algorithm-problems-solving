#include <bits/stdc++.h>
using namespace std;

void initSegtree(vector<int> &st, vector<int> &A, int node, int s, int e)
{
    if (s == e)
    {
        st[node] = A[s];
        return;
    }
    int m = (s + e) / 2;
    initSegtree(st, A, 2 * node, s, m);
    initSegtree(st, A, 2 * node + 1, m + 1, e);
    st[node] = max(st[2 * node], st[2 * node + 1]);
}

void update(vector<int> &st, vector<int> &A, int node, int s, int e, int x, int ind)
{
    if (s == e)
    {
        A[s] -= x;
        st[node] = A[s];
        return;
    }

    int m = (s + e) / 2;
    if (ind <= m)
        update(st, A, 2 * node, s, m, x, ind);
    else
        update(st, A, 2 * node + 1, m + 1, e, x, ind);
    st[node] = max(st[2 * node], st[2 * node + 1]);
}

int query(vector<int> &st, vector<int> &A, int node, int s, int e, int x)
{
    if (st[node] < x)
        return -1;
    if (s == e)
        return s;

    int m = (s + e) / 2;
    if (st[2 * node] >= x)
        return query(st, A, 2 * node, s, m, x);
    return query(st, A, 2 * node + 1, m + 1, e, x);
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
        vector<int> A(n);
        vector<int> st(4 * n);
        vector<int> qans;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        initSegtree(st, A, 1, 0, n - 1);

        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
            int ans = query(st, A, 1, 0, n - 1, x);
            if (ans >= 0)
                update(st, A, 1, 0, n - 1, x, ans);
            cout << ans + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}