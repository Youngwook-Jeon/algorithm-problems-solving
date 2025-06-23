#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (k >= n / 2)
            solve(k, prices);

        vector<vector<int>> dp(k + 1, vector<int>(n));

        for (int i = 1; i <= k; ++i)
        {
            int localMax = -prices[0];
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = max(dp[i][j - 1], prices[j] + localMax);
                localMax = max(localMax, dp[i - 1][j - 1] - prices[j]);
            }
        }

        return dp[k][n - 1];
    }

    int solve(int k, vector<int> &prices)
    {
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
                ans += prices[i] - prices[i - 1];
        }

        return ans;
    }
};