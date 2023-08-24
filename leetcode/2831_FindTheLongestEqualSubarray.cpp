#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        unordered_map<int, int> um;
        int maxFreq = 0, l = 0, r = 0;
        int ans = 0;

        for (r = 0; r < nums.size(); r++)
        {
            um[nums[r]]++;
            maxFreq = max(maxFreq, um[nums[r]]);

            while ((r - l + 1) - maxFreq > k)
            {
                um[nums[l]]--;
                l++;
            }
            ans = maxFreq;
        }

        return ans;
    }
};