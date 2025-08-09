#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, bool> dp;
    int sideLen = 0;
    vector<int> sticks;

    bool makesquare(vector<int>& matchsticks) {
        int totalSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalSum % 4 != 0) {
            return false;
        }

        this->sideLen = totalSum / 4;
        this->sticks = matchsticks;

        sort(this->sticks.begin(), this->sticks.end(), greater<int>());

        return solve((1 << this->sticks.size()) - 1, 0);
    }

    bool solve(int mask, int currentSum) {
        if (mask == 0) {
            return true;
        }

        if (dp.count(mask)) {
            return dp[mask];
        }

        for (int i = 0; i < sticks.size(); ++i) {
            if (mask & (1 << i)) {
                if (currentSum + sticks[i] <= this->sideLen) {
                    if (solve(mask ^ (1 << i), (currentSum + sticks[i]) % this->sideLen)) {
                        return dp[mask] = true;
                    }
                }
            }
        }

        return dp[mask] = false;
    }
};