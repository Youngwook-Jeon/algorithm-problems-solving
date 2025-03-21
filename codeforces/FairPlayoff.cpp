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
    int first = 0, second = 0;
    vi arr(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
        if (arr[i] > first)
            first = arr[i];
    }

    for (int i = 0; i < 4; i++)
    {
        if (arr[i] > second && arr[i] != first)
            second = arr[i];
    }

    int cnt = 0;
    for (int i = 0; i < 2; i++)
    {
        if (arr[i] == first || arr[i] == second)
            cnt++;
    }

    cout << (cnt == 1 ? "YES" : "NO") << newl;
}

int main()
{
    FASTIO
    forEachTestCase solve();

    return 0;
}
