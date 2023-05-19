#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int maxNum = 0;
        unordered_map<int, int> um;

        for (auto num : nums)
        {
            um[num] += num;
            maxNum = max(maxNum, num);
        }

        int twoPast = 0;
        int onePast = (um.find(1) != um.end()) ? um[1] : 0;

        for (int i = 2; i <= maxNum; i++)
        {
            int tmp = onePast;
            int val = (um.find(i) != um.end()) ? um[i] : 0;

            onePast = max(onePast, twoPast + val);
            twoPast = tmp;
        }

        return onePast;
    }
};