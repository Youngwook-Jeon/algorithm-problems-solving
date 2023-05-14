#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        int m = nums.size();
        int tableSize = 1 << m;
        vector<vector<int>> gcdTable(m, vector<int>(m));
        vector<int> table(tableSize, -1);

        for (int i = 0; i < m - 1; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                gcdTable[i][j] = gcd(nums[i], nums[j]);
            }
        }

        int ans = solve(m / 2, 0, gcdTable, nums, table);
        return ans;
    }

    int solve(int step, int mask, vector<vector<int>> &gcdTable, vector<int> &nums, vector<int> &table)
    {
        if (step == 0)
            return 0;

        if (table[mask] != -1)
            return table[mask];

        int ans = INT_MIN;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (((mask >> i) & 1 == 1) || ((mask >> j) & 1) == 1)
                    continue;

                int newMask = mask | (1 << i) | (1 << j);
                ans = max(ans, solve(step - 1, newMask, gcdTable, nums, table) + step * (gcd(nums[i], nums[j])));
            }
        }

        table[mask] = ans;
        return ans;
    }

    int gcd(int num1, int num2)
    {
        if (num1 > num2)
            return gcd(num2, num1);

        if (num1 == 0)
            return num2;
        return gcd(num2 % num1, num1);
    }
};