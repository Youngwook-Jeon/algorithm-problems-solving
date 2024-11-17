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
    int n, m, l;
    cin >> n >> m >> l;
    vector<pii> hurdle(n);
    vector<pii> up(m);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        hurdle[i] = {l, r};
    }

    int power = 0;
    priority_queue<int> pq;
    for (int i = 0; i < m; i++)
    {
        int x, v;
        cin >> x >> v;
        up[i] = {x, v};
    }

    bool able = true;
    int cur = 0, ans = 0;
    for (auto &[l, r] : hurdle)
    {
        int need = r - l + 1 - power;
        while (cur < m && up[cur].first < l)
        {
            pq.push(up[cur].second);
            cur++;
        }

        while (!pq.empty() && need > 0)
        {
            int mx = pq.top();
            pq.pop();
            power += mx;
            need -= mx;
            ans++;
        }

        if (need > 0)
        {
            able = false;
            break;
        }
    }

    if (!able)
    {
        cout << -1 << newl;
    }
    else
    {
        cout << ans << newl;
    }
}

int main()
{
    FASTIO
    forEachTestCase solve();
    return 0;
}
