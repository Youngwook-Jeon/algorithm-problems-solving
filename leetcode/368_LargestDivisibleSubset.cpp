#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n);
        dp[0].push_back(nums[0]);

        for (int i = 1; i < n; ++i)
        {
            vector<int> local;
            for (int j = 0; j < i; ++j)
            {
                if ((nums[i] % nums[j] == 0) && (local.size() <= dp[j].size()))
                {
                    local = dp[j];
                }
            }
            local.push_back(nums[i]);
            dp[i] = local;
        }

        vector<int> ans = dp[0];
        for (int i = 1; i < n; ++i)
        {
            if (ans.size() < dp[i].size())
                ans = dp[i];
        }

        return ans;
    }
};