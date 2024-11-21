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
    vector<vector<int>> a(3);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
            a[0].push_back(i);
        else if (t == 2)
            a[1].push_back(i);
        else
            a[2].push_back(i);
    }

    int w = min(a[0].size(), min(a[1].size(), a[2].size()));

    cout << w << newl;
    while (w)
    {
        cout << a[0][w - 1] << ' ' << a[1][w - 1] << ' ' << a[2][w - 1] << newl;
        w--;
    }

    return 0;
}
