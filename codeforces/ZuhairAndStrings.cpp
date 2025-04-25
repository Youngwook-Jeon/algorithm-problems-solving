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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    char prev = s[0];
    int len = 1;

    if (s.size() == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    vector<vector<int>> a(26);

    for (int i = 1; i < s.size(); i++)
    {
        if (prev == s[i])
        {
            len++;
        }
        else
        {
            if (len >= k)
            {
                a[prev - 'a'].push_back(len);
            }
            len = 1;
            prev = s[i];
        }

        if (i == s.size() - 1 && len >= k)
        {
            a[prev - 'a'].push_back(len);
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        int local = 0;
        for (int num : a[i])
        {
            local += (num / k);
        }
        ans = max(local, ans);
    }

    cout << ans << endl;
    return 0;
}
