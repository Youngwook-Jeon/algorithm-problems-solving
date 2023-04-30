#include <vector>
using namespace std;

typedef long long ll;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        ll bitmask = 0;
        for (int num : nums)
        {
            bitmask ^= num;
        }

        ll rightMostDiff = bitmask & (-bitmask);
        int x = 0;

        for (int num : nums)
        {
            if ((num & rightMostDiff) != 0)
                x ^= num;
        }

        return {x, (int)(bitmask ^ x)};
    }
};