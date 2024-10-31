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
    string s;
    cin >> s;
    if (n < 26)
    {
        cout << "NO" << newl;
        return 0;
    }

    vector<bool> freq(26);
    for (char c : s)
    {
        if (c < 'a')
        {
            freq[c - 'A'] = true;
        }
        else
        {
            freq[c - 'a'] = true;
        }
    }

    bool ans = true;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == false)
        {
            ans = false;
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << newl;

    return 0;
}
