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
    vi w(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i];
    }

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        ans += ceil((double)w[i] / k);
    }

    ans = ceil((double)ans / 2);

    cout << ans << endl;

    return 0;
}
