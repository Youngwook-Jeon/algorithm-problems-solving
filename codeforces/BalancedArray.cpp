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
    int n;
    cin >> n;
    if (n % 4 == 2)
    {
        cout << "NO" << newl;
        return;
    }

    cout << "YES" << newl;
    for (int i = 2; i <= n; i += 2)
    {
        cout << i << ' ';
    }

    int x = n / 2 - 1;
    int val = 1;
    while (x > 0)
    {
        cout << val << ' ';
        val += 2;
        x -= 1;
    }

    cout << n + (n / 2 - 1) << newl;
}

int main()
{
    FASTIO
    forEachTestCase solve();
    return 0;
}
