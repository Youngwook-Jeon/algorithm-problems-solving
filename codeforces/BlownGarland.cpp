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
    string s;
    cin >> s;
    vi a(4);
    map<char, int> mp;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '!')
        {
            ++a[i % 4];
        }
        else
        {
            mp[s[i]] = (i % 4);
        }
    }

    cout << a[mp['R']] << ' ';
    cout << a[mp['B']] << ' ';
    cout << a[mp['Y']] << ' ';
    cout << a[mp['G']] << ' ';
    return 0;
}
