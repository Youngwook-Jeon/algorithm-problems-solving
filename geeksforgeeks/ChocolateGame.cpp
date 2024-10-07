#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(k);
        vector<int> dp(n + 1, 1);

        for (int i = 0; i < k; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (i + v[j] > n)
                    break;
                dp[i + v[j]] = dp[i + v[j]] & (dp[i] ^ 1);
            }
        }

        if (dp[n])
            cout << "GeekB" << '\n';
        else
            cout << "GeekA" << '\n';
    }

    return 0;
}