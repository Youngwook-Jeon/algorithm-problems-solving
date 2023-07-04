#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int pos = 0; pos < 32; pos++)
        {
            int bitSum = 0;
            for (auto num : nums)
            {
                bitSum += (num >> pos) & 1;
            }
            int ansBit = bitSum % 3;
            ans = ans | (ansBit << pos);
        }

        return ans;
    }
};