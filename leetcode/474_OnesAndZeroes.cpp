#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size() + 1)));

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 1; k <= strs.size(); ++k) {
                    int zeroes = 0;
                    int ones = 0;
                    string now = strs[k - 1];
                    for (int l = 0; l < now.size(); ++l) {
                        if (now[l] == '0') zeroes++;
                        else ones++;
                    }
                    dp[i][j][k] = ((i - zeroes >= 0) && (j - ones >= 0)) ? max(dp[i - zeroes][j - ones][k - 1] + 1, dp[i][j][k - 1]) : dp[i][j][k - 1];
                }
            }
        }

        return dp[m][n][strs.size()];
    }
};