#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> table(n);

        for (int s = n - 1; s >= 0; s--)
        {
            for (int e = s; e < n; e++)
            {
                if (e == s)
                {
                    table[s] = nums[s];
                }
                else
                {
                    int takeFirst = nums[s] - table[e];
                    int takeLast = nums[e] - table[e - 1];
                    table[e] = max(takeFirst, takeLast);
                }
            }
        }

        return table[n - 1] >= 0;
    }
};