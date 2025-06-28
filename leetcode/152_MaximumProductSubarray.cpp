#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = nums[0];
        int localMax = nums[0];
        int localMin = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                swap(localMax, localMin);

            localMax = max(nums[i], nums[i] * localMax);
            localMin = min(nums[i], nums[i] * localMin);
            ans = max(ans, localMax);
        }

        return ans;
    }
};