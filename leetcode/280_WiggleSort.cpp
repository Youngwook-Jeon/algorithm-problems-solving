#include <vector>
using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                if (nums[i - 1] <= nums[i])
                    swap(nums[i - 1], nums[i]);
            }
            else
            {
                if (nums[i - 1] >= nums[i])
                    swap(nums[i - 1], nums[i]);
            }
        }
    }
};