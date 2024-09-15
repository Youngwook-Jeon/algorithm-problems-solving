#include <bits/stdc++.h>
using namespace std;

int ans;
int sum;
bool dp[101][10001] = {
    {
        0,
    },
};

class Solution
{
public:
    void find(int pos, int cur_sum, vector<int> &A)
    {
        if (pos >= A.size())
        {
            ans = min(ans, abs(2 * cur_sum - sum));
            return;
        }

        if (dp[pos][cur_sum])
            return;

        dp[pos][cur_sum] = true;
        find(pos + 1, cur_sum, A);
        find(pos + 1, cur_sum + A[pos], A);
    }

    int solve(int N, vector<int> A)
    {
        // code here
        sum = 0;
        for (auto &it : A)
        {
            it = abs(it);
            sum += it;
        }
        ans = sum;
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= sum; j++)
                dp[i][j] = 0;

        find(0, 0, A);

        return ans;
    }
};