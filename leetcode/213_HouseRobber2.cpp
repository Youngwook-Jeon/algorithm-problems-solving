#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int n;

    int rob(vector<int> &nums)
    {
        n = nums.size();
        int x = solve(nums, 2, n - 2) + nums[0];
        int y = solve(nums, 1, n - 1);

        return max(x, y);
    }

    int solve(vector<int> &nums, int start, int end)
    {
        if (start >= n || end >= n || start > end)
            return 0;
        int ans = 0;
        int table[100] = {0};
        table[start] = nums[start];

        for (int i = start + 1; i <= end; i++)
        {
            table[i] = max(table[i - 2] + nums[i], table[i - 1]);
        }

        return table[end];
    }
};