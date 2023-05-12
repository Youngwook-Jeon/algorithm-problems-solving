#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0;
        int l = 0, h = 0, numZeroes = 0;

        while (h < nums.size())
        {
            if (nums[h] == 0)
                numZeroes++;

            while (numZeroes == 2)
            {
                if (nums[l] == 0)
                    numZeroes--;
                l++;
            }

            ans = max(ans, h - l + 1);
            h++;
        }

        return ans;
    }
};