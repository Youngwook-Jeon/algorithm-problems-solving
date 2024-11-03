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

int money[5] = {1, 5, 10, 20, 100};

int main()
{
    FASTIO
    int n;
    cin >> n;
    int ind = 4, ans = 0, cur = n;
    while (ind >= 0)
    {
        ans += cur / money[ind];
        cur %= money[ind];
        ind--;
    }

    cout << ans << newl;

    return 0;
}
