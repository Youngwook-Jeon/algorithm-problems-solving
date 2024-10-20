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
    vector<bool> levels(n + 1);
    int p, q;
    cin >> p;
    while (p--)
    {
        int a;
        cin >> a;
        levels[a] = true;
    }
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        levels[a] = true;
    }

    bool ans = true;
    for (int i = 1; i <= n; i++)
    {
        if (levels[i] == false)
        {
            ans = false;
            break;
        }
    }

    cout << (ans ? "I become the guy." : "Oh, my keyboard!") << newl;
    return 0;
}
