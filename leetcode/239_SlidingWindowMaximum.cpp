#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k == 1)
            return nums;

        vector<int> ans(n - k + 1, 0);
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        leftMax[0] = nums[0];
        rightMax[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
        {
            if (i % k == 0)
                leftMax[i] = nums[i];
            else
                leftMax[i] = max(leftMax[i - 1], nums[i]);

            int j = n - i - 1;
            if ((j + 1) % k == 0)
                rightMax[j] = nums[j];
            else
                rightMax[j] = max(rightMax[j + 1], nums[j]);
        }

        for (int i = 0; i < n - k + 1; i++)
        {
            ans[i] = max(rightMax[i], leftMax[i + k - 1]);
        }

        return ans;
    }
};