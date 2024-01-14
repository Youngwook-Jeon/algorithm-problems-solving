#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> um;
        um.insert({0, 1});
        int sum = 0, ans = 0;
        for (auto num : nums)
        {
            sum += num;
            if (um.find(sum - k) != um.end())
                ans += um[sum - k];
            um[sum] += 1;
        }

        return ans;
    }
};