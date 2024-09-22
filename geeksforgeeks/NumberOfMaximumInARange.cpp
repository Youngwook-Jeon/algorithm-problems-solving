#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void buildSegtree(vector<pii> &st, vector<int> &A, int node, int s, int e)
{
    if (s == e)
    {
        st[node] = make_pair(1, A[s]);
        return;
    }

    int m = (s + e) / 2;
    buildSegtree(st, A, 2 * node, s, m);
    buildSegtree(st, A, 2 * node + 1, m + 1, e);
    pii x = st[2 * node];
    pii y = st[2 * node + 1];
    if (x.second == y.second)
    {
        st[node] = make_pair(x.first + y.first, x.second);
    }
    else if (x.second > y.second)
    {
        st[node] = make_pair(x.first, x.second);
    }
    else
    {
        st[node] = make_pair(y.first, y.second);
    }
}

void update(vector<pii> &st, vector<int> &A, int node, int s, int e, int ind, int val)
{
    if (ind < s || ind > e)
        return;
    if (s == e)
    {
        A[s] = val;
        st[node] = make_pair(1, A[s]);
        return;
    }

    int m = (s + e) / 2;
    update(st, A, 2 * node, s, m, ind, val);
    update(st, A, 2 * node + 1, m + 1, e, ind, val);
    pii x = st[2 * node];
    pii y = st[2 * node + 1];
    if (x.second == y.second)
    {
        st[node] = make_pair(x.first + y.first, x.second);
    }
    else if (x.second > y.second)
    {
        st[node] = make_pair(x.first, x.second);
    }
    else
    {
        st[node] = make_pair(y.first, y.second);
    }
}

pii query(vector<pii> &st, vector<int> &A, int node, int s, int e, int qs, int qe)
{
    if (s > qe || e < qs)
    {
        return {-1, -1};
    }

    if (qs <= s && e <= qe)
        return st[node];

    int m = (s + e) / 2;
    pii x = query(st, A, 2 * node, s, m, qs, qe);
    pii y = query(st, A, 2 * node + 1, m + 1, e, qs, qe);
    if (x.second == y.second)
    {
        return make_pair(x.first + y.first, x.second);
    }
    else if (x.second > y.second)
    {
        return make_pair(x.first, x.second);
    }
    else
    {
        return make_pair(y.first, y.second);
    }
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
        vector<pii> st(4 * n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        buildSegtree(st, A, 1, 0, n - 1);

        for (int i = 0; i < q; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            b--;
            if (a == 1)
            {
                update(st, A, 1, 0, n - 1, b, c);
            }
            else
            {
                cout << query(st, A, 1, 0, n - 1, b, --c).first << '\n';
            }
        }
    }
    return 0;
}