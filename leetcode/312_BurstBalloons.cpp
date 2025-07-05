#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> new_nums(n + 2);
        new_nums[0] = new_nums[n + 1] = 1;
        for (int i = 0; i < n; i++)
        {
            new_nums[i + 1] = nums[i];
        }

        int new_n = n + 2;
        vector<vector<int>> dp(new_n, vector<int>(new_n));

        for (int len = 2; len < new_n; ++len)
        {
            for (int i = 0; i < new_n - len; ++i)
            {
                int j = i + len;
                for (int k = i + 1; k < j; ++k)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + new_nums[i] * new_nums[k] * new_nums[j]);
                }
            }
        }

        return dp[0][n + 1];
    }
};
