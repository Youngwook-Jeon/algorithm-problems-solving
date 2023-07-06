#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double maxVal = INT_MIN;
        double minVal = INT_MAX;

        for (auto num : nums)
        {
            maxVal = max(maxVal, (double)num);
            minVal = min(minVal, (double)num);
        }
        double prev = maxVal, error = INT_MAX;
        while (error > 0.00001)
        {
            double mid = (maxVal + minVal) * 0.5;
            if (canHaveMaxAvg(mid, k, nums))
            {
                minVal = mid;
            }
            else
            {
                maxVal = mid;
            }
            error = abs(prev - mid);
            prev = mid;
        }

        return minVal;
    }

    bool canHaveMaxAvg(double mid, int k, vector<int> &nums)
    {
        double sum = 0, prev = 0, minSum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i] - mid;
        }
        if (sum >= 0)
            return true;

        for (int i = k; i < nums.size(); i++)
        {
            sum += nums[i] - mid;
            prev += nums[i - k] - mid;
            minSum = min(minSum, prev);
            if (sum >= minSum)
                return true;
        }

        return false;
    }
};