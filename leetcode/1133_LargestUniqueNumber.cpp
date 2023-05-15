#include <vector>
using namespace std;

class Solution
{
public:
    int largestUniqueNumber(vector<int> &nums)
    {
        int freq[1001]{0};
        int ans = -1;
        for (auto num : nums)
        {
            freq[num]++;
        }

        for (int i = 0; i <= 1000; i++)
        {
            if (freq[i] == 1)
                ans = i;
        }

        return ans;
    }
};