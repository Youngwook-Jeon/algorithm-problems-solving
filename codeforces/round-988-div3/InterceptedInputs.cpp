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
    int k;
    cin >> k;
    unordered_map<int, int> um;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        if (a <= k - 2)
            um[a]++;
    }

    for (auto &[val, freq] : um)
    {
        if ((k - 2) % val == 0)
        {
            int other = (k - 2) / val;
            if (other == val && freq >= 2)
            {
                cout << val << ' ' << val << newl;
                return;
            }
            else if (other != val && um.find(other) != um.end())
            {
                cout << val << ' ' << other << newl;
                return;
            }
        }
    }
}

int main()
{
    FASTIO
    forEachTestCase solve();
    return 0;
}
