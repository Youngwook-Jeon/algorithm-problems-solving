#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    // Tabulation:
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<ll>> dp(amount + 1, vector<ll>(n + 1));

    //     for (int i = 0; i <= n; ++i) {
    //         dp[0][i] = 1;
    //     }

    //     for (int a = 0; a <= amount; ++a) {
    //         for (int i = 1; i <= n; ++i) {
    //             if (coins[i - 1] <= a) {
    //                 dp[a][i] = dp[a - coins[i - 1]][i] + dp[a][i - 1];
    //             } else {
    //                 dp[a][i] = dp[a][i - 1];
    //             }
    //         }
    //     }

    //     return dp[amount][n];
    // }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if (amount == 0) return 1;

        vector<vector<int>> dp(amount + 1, vector<int>(n + 1, -1));

        for (int i = 0; i <= n; ++i) {
            dp[0][i] = 1;
        }

        return solve(amount, n, coins, dp);
    }

    int solve(int amount, int n, vector<int>& coins, vector<vector<int>>& dp) {
        if (n == 0) return 0;
        if (amount == 0) return 1;
        if (dp[amount][n] != -1) return dp[amount][n];

        if (coins[n - 1] <= amount) {
            return dp[amount][n] = solve(amount - coins[n - 1], n, coins, dp) + solve(amount, n - 1, coins, dp);
        } 

        return dp[amount][n] = solve(amount, n - 1, coins, dp);
    }
};