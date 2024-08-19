#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll k;
    cin >> n >> k;
    vector<vector<int>> p(60, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        cin >> p[0][i];
    }

    for (int i = 1; i < 60; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[i][j] = p[i - 1][p[i - 1][j]];
        }
    }

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> q(n + 1);
    for (int i = 1; i <= n; i++)
    {
        q[i] = i;
    }

    for (int i = 0; i < 60; i++)
    {
        if (k % 2)
        {
            for (int j = 1; j <= n; j++)
            {
                q[j] = p[i][q[j]];
            }
        }
        k /= 2;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[q[i]] << ' ';
    }
    return 0;
}