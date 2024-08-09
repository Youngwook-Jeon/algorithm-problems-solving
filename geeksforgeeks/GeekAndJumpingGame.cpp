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
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> k;

        vector<int> dp(n);
        deque<int> dq;
        dp[0] = arr[0];
        dq.push_back(0);
        for (int i = 1; i < n; i++)
        {
            while (!dq.empty() && dq.front() < i - k)
            {
                dq.pop_front();
            }

            if (!dq.empty())
            {
                dp[i] = arr[i] + dp[dq.front()];
            }

            while (!dq.empty() && dp[i] >= dp[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        cout << dp[n - 1] << '\n';
    }
    return 0;
}