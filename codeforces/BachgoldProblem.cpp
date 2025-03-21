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
    vi arr;
    while (n)
    {
        if (n == 3)
        {
            arr.push_back(3);
            n = 0;
        }
        else
        {
            arr.push_back(2);
            n -= 2;
        }
    }

    cout << arr.size() << newl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
}

int main()
{
    FASTIO
    solve();
    return 0;
}
