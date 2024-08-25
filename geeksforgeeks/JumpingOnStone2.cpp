#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<int> dp(n + 1, 1e9);
        dp[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k && i + j <= n; j++)
            {
                dp[i + j] = min(dp[i + j], dp[i] + abs(v[i + j - 1] - v[i - 1]));
            }
        }

        cout << dp[n] << '\n';
    }
    return 0;
}