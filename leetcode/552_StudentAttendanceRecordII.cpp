#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class Solution {
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(n, 0, 0, dp);
    }

    int solve(int n, int nAbsences, int cLates, vector<vector<vector<int>>>& dp) {
        if (nAbsences >= 2 || cLates >= 3) return 0;
        if (n == 0) return 1;
        if (dp[n][nAbsences][cLates] != -1) return dp[n][nAbsences][cLates];

        int cnt = solve(n - 1, nAbsences, 0, dp);
        cnt = (solve(n - 1, nAbsences + 1, 0, dp) + cnt) % MOD;
        cnt = (solve(n - 1, nAbsences, cLates + 1, dp) + cnt) % MOD;

        return dp[n][nAbsences][cLates] = cnt;
    }
};