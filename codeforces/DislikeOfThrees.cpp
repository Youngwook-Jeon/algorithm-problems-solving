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

vi v;

void solve()
{
    int k;
    cin >> k;
    cout << v[k - 1] << newl;
}

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
    for (int i = 1; i <= 2000; i++)
    {
        if (i % 10 != 3 && i % 3 != 0)
            v.push_back(i);
    }
    forEachTestCase solve();
    return 0;
}
