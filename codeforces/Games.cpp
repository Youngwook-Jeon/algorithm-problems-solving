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
    vector<pii> teams(n);
    for (int i = 0; i < n; i++)
    {
        int h, a;
        cin >> h >> a;
        teams[i] = make_pair(h, a);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        pii home = teams[i];
        for (int j = 0; j < n; j++)
        {
            if (home.first == teams[j].second)
                ans++;
        }
    }

    cout << ans << newl;

    return 0;
}
