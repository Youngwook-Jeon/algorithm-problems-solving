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
    int prev = n % 10 - 1, ans = 0;
    ans += 10 * prev;
    for (int i = 1; i <= 4 && n > 0; i++)
    {
        n /= 10;
        ans += i;
    }

    cout << ans << newl;
}

int main()
{
    FASTIO
    forEachTestCase solve();
    return 0;
}
