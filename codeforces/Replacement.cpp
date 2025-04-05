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
    string s, r;
    cin >> s >> r;

    sort(s.begin(), s.end());

    int boundary = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            boundary = i;
            break;
        }
    }

    int zeros = boundary + 1, ones = n - zeros;

    for (int i = 0; i < r.size(); i++)
    {
        if (boundary == -1 || zeros == 0 || ones == 0)
        {
            cout << "NO" << newl;
            return;
        }
        else if (r[i] == '1')
        {
            boundary--;
            zeros--;
        }
        else
        {
            ones--;
        }
    }

    cout << (zeros + ones == 1 ? "YES" : "NO") << newl;
}

int main()
{
    FASTIO
    forEachTestCase solve();
    return 0;
}
