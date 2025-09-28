#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = ((ll)dp[i][j - 1] + dp[i - 1][j]) % MOD;
                if (j >= i) {
                    dp[i][j] = ((ll)MOD + dp[i][j] - dp[i - 1][j - i]) % MOD;
                }
            }
        }

        return dp[n][k];
    }
};