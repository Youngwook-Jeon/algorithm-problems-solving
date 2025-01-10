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

vi timur(52, 0);

void use_file_input_output()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void makeDict(string name, vi &arr)
{
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] >= 'a')
        {
            arr[name[i] - 'A' - 6]++;
        }
        else
        {
            arr[name[i] - 'A']++;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi arr(52, 0);
    makeDict(s, arr);
    for (int i = 0; i < 52; i++)
    {
        if (arr[i] != timur[i])
        {
            cout << "NO" << newl;
            return;
        }
    }

    cout << "YES" << newl;
}

int main()
{
    string name = "Timur";
    makeDict(name, timur);
    FASTIO
    forEachTestCase solve();
    return 0;
}
