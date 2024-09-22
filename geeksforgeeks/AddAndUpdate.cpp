#include <bits/stdc++.h>
using namespace std;

int query(int node, int s, int e, int qs, int qe, vector<int> &st)
{
    if (qe < s || e < qs)
        return 0;

    if (qs <= s && e <= qe)
        return st[node];

    int m = (s + e) / 2;
    return query(2 * node, s, m, qs, qe, st) + query(2 * node + 1, m + 1, e, qs, qe, st);
}

void update(int node, int s, int e, int ind, int val, vector<int> &st)
{
    if (e < ind || s > ind)
        return;
    if (s == e)
    {
        st[node] = val;
        return;
    }

    int m = (s + e) / 2;
    update(2 * node, s, m, ind, val, st);
    update(2 * node + 1, m + 1, e, ind, val, st);
    st[node] = st[2 * node] + st[2 * node + 1];
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
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            update(1, 0, n - 1, i, A[i], st);
        }

        for (int i = 0; i < q; i++)
        {
            int inst, a, b;
            cin >> inst >> a >> b;
            a--;
            if (inst == 1)
            {
                A[a] = b;
                update(1, 0, n - 1, a, b, st);
            }
            else
            {
                cout << query(1, 0, n - 1, a, --b, st) << '\n';
            }
        }
    }
    return 0;
}