#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        int n = s1.size();
        vector dp(n + 1, vector(n, vector<int>(n)));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i < n + 1 - len; ++i)
            {
                for (int j = 0; j < n + 1 - len; ++j)
                {
                    for (int newLen = 1; newLen < len; ++newLen)
                    {
                        dp[len][i][j] |= (dp[newLen][i][j] && dp[len - newLen][i + newLen][j + newLen]);
                        dp[len][i][j] |= (dp[newLen][i][j + len - newLen] && dp[len - newLen][i + newLen][j]);
                    }
                }
            }
        }

        return dp[n][0][0];
    }
};