#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int N = 2e5 + 17;
mt19937_64 rnd(5017);
int a[N], b[N];
ull sa[N], sb[N];
ull w[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        w[i] = rnd();
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sa[i] = sa[i - 1] + w[a[i]];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        sb[i] = sb[i - 1] + w[b[i]];
    }

    for (int i = 1; i <= q; i++)
    {
        int la, ra, lb, rb;
        cin >> la >> ra >> lb >> rb;
        bool ans = (sa[ra] - sa[la - 1] == sb[rb] - sb[lb - 1]);
        cout << (ans ? "Yes" : "No") << '\n';
    }
    return 0;
}