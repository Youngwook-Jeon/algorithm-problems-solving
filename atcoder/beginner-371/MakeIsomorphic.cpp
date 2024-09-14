#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, h;
    cin >> n >> m;
    set<pii> edges_g, edges_h;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges_g.emplace(u, v);
        edges_g.emplace(v, u);
    }

    cin >> h;
    for (int i = 1; i <= h; i++)
    {
        int a, b;
        cin >> a >> b;
        edges_h.emplace(a, b);
        edges_h.emplace(b, a);
    }

    vector<vector<int>> A(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    vector<int> perm(n);
    iota(begin(perm), end(perm), 1);

    int ans = 28000000;

    do
    {
        int local = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                local += A[i][j] * (edges_h.count({i, j}) != edges_g.count({perm[i - 1], perm[j - 1]}));
            }
        }
        ans = min(ans, local);
    } while (next_permutation(begin(perm), end(perm)));

    cout << ans << '\n';

    return 0;
}
