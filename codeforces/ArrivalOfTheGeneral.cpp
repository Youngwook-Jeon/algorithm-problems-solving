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
    int n;
    cin >> n;
    vi a(n + 1);
    int mn = 101, mx = -1;
    int mnPos = -1, mxPos = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] <= mn)
        {
            mn = a[i];
            mnPos = i;
        }

        if (a[i] > mx)
        {
            mx = a[i];
            mxPos = i;
        }
    }

    if (mn == mx)
    {
        cout << 0 << newl;
        return 0;
    }

    int additional = (mnPos < mxPos ? 1 : 0);

    cout << (n - mnPos + mxPos - 1 - additional) << newl;

    return 0;
}
