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

int main()
{
    FASTIO
    int n, m;
    cin >> n;
    vector<pii> vc(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vc[i] = make_pair(a, b);
    }

    cin >> m;
    vector<pii> vp(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        vp[i] = make_pair(a, b);
    }

    auto compareFirst = [&](pii p1, pii p2)
    { return p1.first < p2.first; };
    auto compareLast = [&](pii p1, pii p2)
    { return p1.second < p2.second; };

    int ans = 0;

    sort(vc.begin(), vc.end(), compareLast);
    sort(vp.begin(), vp.end(), compareFirst);
    pii c, p;

    c = vc.front();
    p = vp.back();
    ans = max(ans, p.first - c.second);

    sort(vc.begin(), vc.end(), compareFirst);
    sort(vp.begin(), vp.end(), compareLast);

    c = vc.back();
    p = vp.front();
    ans = max(ans, c.first - p.second);

    cout << ans;
    return 0;
}
