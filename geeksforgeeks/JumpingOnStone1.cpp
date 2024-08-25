#include <bits/stdc++.h>
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        vector<int> dp(n + 1);
        dp[0] = 1e5;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]),
                        dp[i - 2] + abs(arr[i] - arr[i - 2]));
        }

        cout << dp[n] << '\n';
    }
    return 0;
}