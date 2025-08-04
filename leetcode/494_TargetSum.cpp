#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, vector<unordered_map<int, int>> &dp, int target, int cur)
    {
        if (cur == nums.size() - 1)
            return dp[cur][target];

        if (dp[cur].count(target))
            return dp[cur][target];

        dp[cur][target] = solve(nums, dp, target - nums[cur], cur + 1) + solve(nums, dp, target + nums[cur], cur + 1);

        return dp[cur][target];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        vector<unordered_map<int, int>> dp(nums.size());
        int last = nums.back();
        dp[nums.size() - 1][last] = 1;
        dp[nums.size() - 1][-last] += 1;

        return solve(nums, dp, target, 0);
    }
};