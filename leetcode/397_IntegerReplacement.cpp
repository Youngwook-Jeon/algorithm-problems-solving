#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int integerReplacement(int n)
    {
        unordered_map<int, int> dp;
        dp[1] = 0;
        return solve(n, dp);
    }

    int solve(int n, unordered_map<int, int> &dp)
    {
        if (n == 1)
            return dp[1];
        if (dp.count(n))
            return dp[n];

        if (n % 2 == 0)
        {
            dp[n] = solve(n / 2, dp) + 1;
        }
        else
        {
            dp[n] = min(solve(n / 2 + 1, dp), solve(n / 2, dp)) + 2;
        }

        return dp[n];
    }
};