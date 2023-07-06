#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isMajorityElement(vector<int> &nums, int target)
    {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return (l + nums.size() / 2 < nums.size()) && nums[l + nums.size() / 2] == target;
    }
};