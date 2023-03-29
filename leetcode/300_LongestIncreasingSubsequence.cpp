#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Solution1: Dynamic programming
    int lengthOfLIS1(vector<int> &nums)
    {
        vector<int> table(2500, 1);
        int ans = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    table[i] = max(table[i], table[j] + 1);
                }
            }

            ans = max(ans, table[i]);
        }

        return ans;
    }

    // Solution2: Binary search
    int lengthOfLIS2(vector<int> &nums)
    {
        vector<int> v;
        v.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > v[v.size() - 1])
            {
                v.push_back(nums[i]);
            }
            else
            {
                int pos = binarySearch(v, nums[i]);
                v[pos] = nums[i];
            }
        }

        return v.size();
    }

    int binarySearch(vector<int> &v, int target)
    {
        int l = 0, h = v.size() - 1;

        while (l < h)
        {
            int mid = (h - l) / 2 + l;
            if (v[mid] == target)
                return mid;

            if (v[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
        }

        return l;
    }
};