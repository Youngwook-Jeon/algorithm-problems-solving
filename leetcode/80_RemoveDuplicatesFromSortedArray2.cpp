#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int removeDuplicates1(vector<int> &nums)
    {
        int ans = nums.size();
        int cnt = 1, i = 1;
        int prev = nums[0];
        while (i < nums.size())
        {
            int cur = nums[i];
            if (cur == prev)
            {
                cnt++;
                if (cnt >= 3)
                {
                    nums[i] = INT_MAX;
                    ans--;
                }
            }
            else
            {
                cnt = 1;
                prev = nums[i];
            }
            i++;
        }
        sort(nums.begin(), nums.end());

        return ans;
    }

    int removeDuplicates2(vector<int> &nums)
    {
        int j = 1, cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
                cnt++;
            else
                cnt = 1;

            if (cnt <= 2)
            {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};