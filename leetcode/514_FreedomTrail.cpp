#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, n, dp, ring, key);
    }

    int solve(int cur, int keyInd, int n, vector<vector<int>>& dp, string& ring, string& key) {
        if (keyInd == n) return 0;
        if (dp[cur][keyInd] != -1) return dp[cur][keyInd];

        int res = INT_MAX;
        for (int i = 0; i < ring.size(); ++i) {
            if (ring[i] == key[keyInd]) {
                int rotateA = max(cur - i, i - cur);
                int rotateB = ring.size() - rotateA;
                int local = min(rotateA, rotateB);
                local += solve(i, keyInd + 1, n, dp, ring, key) + 1;
                res = min(res, local);
            }
        }

        return dp[cur][keyInd] = res;
    }
};