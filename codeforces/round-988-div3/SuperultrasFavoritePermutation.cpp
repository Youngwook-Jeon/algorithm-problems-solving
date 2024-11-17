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

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    else
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;
    if (n < 5)
    {
        cout << -1 << newl;
        return;
    }
    int oddLast, evenFirst;
    if (n % 2 == 0)
        oddLast = n - 1;
    else
        oddLast = n;
    for (int i = 2; i <= n; i += 2)
    {
        if (!isPrime(oddLast + i))
        {
            evenFirst = i;
            break;
        }
    }

    for (int i = 1; i <= oddLast; i += 2)
    {
        cout << i << ' ';
    }

    cout << evenFirst << ' ';

    for (int i = 2; i <= n; i += 2)
    {
        if (i == evenFirst)
            continue;
        cout << i << ' ';
    }
    cout << newl;
}

int main()
{
    FASTIO
    forEachTestCase solve();
    return 0;
}
