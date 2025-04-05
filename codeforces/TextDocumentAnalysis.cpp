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

    bool inPar = false;
    int len = 0, cnt = 0, localLen = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '_' && !inPar)
        {
            len = max(len, localLen);
            localLen = 0;
        }
        else if (s[i] == '_' && inPar)
        {
            if (localLen)
                cnt++;
            localLen = 0;
        }
        else if (s[i] == '(')
        {
            len = max(len, localLen);
            localLen = 0;
            inPar = true;
        }
        else if (s[i] == ')')
        {
            if (localLen)
                cnt++;
            localLen = 0;
            inPar = false;
        }
        else
        {
            localLen++;
        }
    }

    if (localLen)
        len = max(len, localLen);

    cout << len << ' ' << cnt << endl;
    return 0;
}
