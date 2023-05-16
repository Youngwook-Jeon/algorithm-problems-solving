#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        vector<vector<int>> ans;
        if (nums.size() == 0)
        {
            ans.push_back({lower, upper});
            return ans;
        }

        if (nums[0] - lower >= 1)
        {
            ans.push_back({lower, nums[0] - 1});
        }

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] >= 2)
            {
                ans.push_back({nums[i - 1] + 1, nums[i] - 1});
            }
        }

        if (upper - nums.back() >= 1)
        {
            ans.push_back({nums.back() + 1, upper});
        }

        return ans;
    }
};