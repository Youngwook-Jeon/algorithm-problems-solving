#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<ll, int>> dp(n);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ll diff = (ll)nums[i] - nums[j];
                if (dp[j].find(diff) != dp[j].end()) {
                    ans += dp[j][diff];
                    dp[i][diff] += (dp[j][diff] + 1);
                } else {
                    dp[i][diff] += 1;
                }
            }
        }

        return ans;
    }
};