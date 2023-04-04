#include <vector>
using namespace std;

class Solution
{
public:
    int missingElement(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (numOfMissed(n - 1, nums) < k)
        {
            return nums[n - 1] + k - numOfMissed(n - 1, nums);
        }
        int l = 0, h = n - 1;

        // Find an index l such that numOfMissed(l - 1, nums) < k <= numOfMissed(l, nums)
        while (l < h)
        {
            int mid = (h - l) / 2 + l;
            if (numOfMissed(mid, nums) < k)
                l = mid + 1;
            else
                h = mid;
        }

        return nums[l - 1] + k - numOfMissed(l - 1, nums);
    }

    int numOfMissed(int ind, vector<int> &nums)
    {
        return nums[ind] - nums[0] - ind;
    }
};