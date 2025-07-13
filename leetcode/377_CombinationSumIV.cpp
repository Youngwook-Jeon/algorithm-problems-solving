#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int combinationSum4(vector<int>& nums, int target) {
    //     vector<unsigned int> dp(target + 1);
    //     dp[0] = 1;

    //     return solve(nums, dp, target);
    // }

    // int solve(vector<int>& nums, vector<unsigned int>& dp, int cur) {
    //     if (dp[cur] != 0) return dp[cur];

    //     for (int i = 0; i < nums.size(); ++i) {
    //         int next = cur - nums[i];
    //         if (next >= 0) {
    //             dp[cur] += solve(nums, dp, next);
    //         }
    //     }

    //     return dp[cur];
    // }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= target; ++i)
        {
            for (auto n : nums)
            {
                if (i - n >= 0)
                    dp[i] += dp[i - n];
            }
        }

        return dp[target];
    }
};