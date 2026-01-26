#include <bits/stdc++.h>
using namespace std;

class Solution {
    int memo[101][101][101];

public:
    int removeBoxes(vector<int>& boxes) {
        memset(memo, 0, sizeof(memo));

        vector<pair<int, int>> groups;
        for (int x : boxes) {
            if (!groups.empty() && groups.back().first == x) {
                groups.back().second++;
            } else {
                groups.push_back({x, 1});
            }
        }

        return solve(groups, 0, groups.size() - 1, 0);
    }

    int solve(vector<pair<int, int>>& groups, int i, int j, int k) {
        if (i > j) return 0;
        if (memo[i][j][k] > 0) return memo[i][j][k];

        int res = (groups[i].second + k) * (groups[i].second + k) + solve(groups, i + 1, j, 0);

        for (int t = i + 1; t <= j; ++t) {
            if (groups[i].first == groups[t].first) {
                res = max(res, solve(groups, i + 1, t - 1, 0) + solve(groups, t, j, k + groups[i].second));
            }
        }

        return memo[i][j][k] = res;
    }
};