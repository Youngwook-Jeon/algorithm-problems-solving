#include <vector>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int ans = 0, dp = 0;

        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                dp++;
                ans += dp;
            }
            else
                dp = 0;
        }

        return ans;
    }
};