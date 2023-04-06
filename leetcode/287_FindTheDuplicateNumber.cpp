#include <vector>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int cur = abs(nums[i]);
            if (nums[cur] < 0)
            {
                ans = cur;
                break;
            }
            nums[cur] *= -1;
        }

        for (auto &num : nums)
        {
            num *= -1;
        }

        return ans;
    }
};