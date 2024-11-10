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
    vi v;
    int m = n;

    int mult = 1;
    while (m)
    {
        int r = m % 10;
        if (r != 0)
        {
            v.push_back(r * mult);
        }
        mult *= 10;
        m /= 10;
    }
    cout << v.size() << newl;

    for (int summand : v)
    {
        cout << summand << ' ';
    }
    cout << newl;
}

int main()
{
    FASTIO
    forEachTestCase solve();

    return 0;
}