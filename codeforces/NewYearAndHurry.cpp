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
    int n, k;
    cin >> n >> k;
    int remain = 240 - k;
    int ans = 0;
    for (int i = n; i >= 0; i--)
    {
        if ((5 * i * (i + 1) / 2) <= remain)
        {
            ans = i;
            break;
        }
    }

    cout << ans << newl;
    return 0;
}
