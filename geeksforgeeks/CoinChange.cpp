#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int su, n;
        cin >> su >> n;
        vector<int> coins(n);
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }

        vector<vector<ll>> dp(n + 1, vector<ll>(su + 1));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= su; j++)
            {
                dp[i][j] += dp[i - 1][j];
                if (j >= coins[i - 1])
                {
                    int k = j - coins[i - 1];
                    while (k >= 0)
                    {
                        dp[i][j] += dp[i - 1][k];
                        k -= coins[i - 1];
                    }
                }
            }
        }

        cout << dp[n][su] << '\n';
    }
    return 0;
}