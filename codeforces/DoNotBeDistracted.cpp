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
    string s;
    cin >> s;
    set<char> tasks;
    tasks.insert(s[0]);

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            continue;

        if (tasks.find(s[i]) == tasks.end())
        {
            tasks.insert(s[i]);
        }
        else
        {
            cout << "NO" << newl;
            return;
        }
    }

    cout << "YES" << newl;
}

int main()
{
    FASTIO
    forEachTestCase solve();
    return 0;
}
