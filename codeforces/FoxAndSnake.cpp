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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> table(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < m; j++)
        {
            table[i][j] = '#';
        }
    }

    for (int i = 1; i < n; i += 2)
    {
        if (i % 4 == 1)
            table[i][m - 1] = '#';
        else
            table[i][0] = '#';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << table[i][j];
        }
        cout << newl;
    }
    return 0;
}
