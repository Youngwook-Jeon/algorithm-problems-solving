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
    deque<int> di;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        di.push_back(a);
    }

    int sereja = 0, dima = 0;
    for (int turn = 1; turn <= n; turn++)
    {
        int f = di.front(), b = di.back();
        if (f < b)
            di.pop_back();
        else
            di.pop_front();
        int mx = max(f, b);
        if (turn % 2 == 1)
        {
            sereja += mx;
        }
        else
        {
            dima += mx;
        }
    }

    cout << sereja << ' ' << dima << newl;
    return 0;
}
