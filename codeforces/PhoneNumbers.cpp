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

string solve(const string &s, int n)
{
    string ans = "";
    if (n == 0)
        return ans;

    for (int i = 0; i < n - 1; i += 2)
    {
        ans += s.substr(i, 2);
        if (i != n - 2)
            ans.push_back('-');
    }

    return ans;
}

int main()
{
    FASTIO
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans = "";
    if (n % 2 == 0)
    {
        ans = solve(s, n);
    }
    else if (n == 3)
    {
        ans = s;
    }
    else
    {
        ans = s.substr(0, 3) + '-' + solve(s.substr(3), n - 3);
    }

    cout << ans << endl;
    return 0;
}
