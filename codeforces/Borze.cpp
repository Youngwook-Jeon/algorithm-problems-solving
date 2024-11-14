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
    string s, ans = "";
    cin >> s;

    char prev = '*';

    for (int i = 0; i < s.size(); i++)
    {
        char now = s[i];
        if (now == '.')
        {
            if (prev == '-')
                ans.push_back('1');
            else
                ans.push_back('0');
            prev = '.';
        }
        else
        {
            if (prev == '-')
            {
                ans.push_back('2');
                prev = '*';
            }
            else
                prev = '-';
        }
    }

    cout << ans << newl;

    return 0;
}
