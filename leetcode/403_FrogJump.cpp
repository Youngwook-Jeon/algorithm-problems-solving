#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<int, bool> dp;

public:
    bool canCross(vector<int> &stones)
    {
        return solve(stones, 0, 0);
    }

    bool solve(vector<int> &stones, int pos = 0, int k = 0)
    {
        int key = (k << 11) | pos;
        if (dp.find(key) != dp.end())
            return dp[key];

        for (int i = pos + 1; i < stones.size(); ++i)
        {
            int diff = stones[i] - stones[pos];
            if (diff < k - 1)
                continue;
            else if (diff > k + 1)
                return dp[key] = false;

            if (solve(stones, i, diff))
            {
                return dp[key] = true;
            }
        }

        return dp[key] = (pos == stones.size() - 1);
    }
};