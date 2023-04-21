#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int table[1001][51];

    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefixSum(n + 1);

        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        for (int subArrCnt = 1; subArrCnt <= k; subArrCnt++)
        {
            for (int currInd = 0; currInd < n; currInd++)
            {
                if (subArrCnt == 1)
                {
                    table[currInd][subArrCnt] = prefixSum[n] - prefixSum[currInd];
                    continue;
                }

                int minLargestSubArrSum = INT_MAX;
                for (int i = currInd; i <= n - subArrCnt; i++)
                {
                    int firstArrSum = prefixSum[i + 1] - prefixSum[currInd];
                    int maxSubArrSum = max(firstArrSum, table[i + 1][subArrCnt - 1]);
                    minLargestSubArrSum = min(minLargestSubArrSum, maxSubArrSum);

                    if (firstArrSum >= minLargestSubArrSum)
                    {
                        break;
                    }
                }

                table[currInd][subArrCnt] = minLargestSubArrSum;
            }
        }

        return table[0][k];
    }
};