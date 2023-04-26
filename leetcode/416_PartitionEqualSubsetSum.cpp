#include <vector>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int total = 0, n = nums.size();
        for (int num : nums)
        {
            total += num;
        }
        if (total % 2 == 1)
            return false;
        int target = total / 2;

        vector<vector<bool>> table(n + 1, vector<bool>(target + 1, false));
        table[0][0] = true;

        for (int i = 1; i <= n; i++)
        {
            int cur = nums[i - 1];
            for (int j = 0; j <= target; j++)
            {
                if (j < cur)
                    table[i][j] = table[i - 1][j];
                else
                    table[i][j] = table[i - 1][j] || table[i - 1][j - cur];
            }
        }

        return table[n][target];
    }
};