#include <vector>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int ans = 0, n = nums.size();
        int i = 0, j = 0;
        while (j < n)
        {
            if (nums[j] == 0)
                k--;

            if (k < 0)
            {
                k += (1 - nums[i]);
                i++;
            }
            j++;
        }

        return j - i;
    }
};