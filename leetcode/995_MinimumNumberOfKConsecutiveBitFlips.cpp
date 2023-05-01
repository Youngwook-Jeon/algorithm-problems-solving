#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int ans = 0, n = nums.size();
        queue<int> isFlipped;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                if (isFlipped.empty() || isFlipped.size() % 2 == 0)
                {
                    ans++;
                    isFlipped.push(i + k - 1);
                }
            }
            else
            {
                if (isFlipped.size() % 2 == 1)
                {
                    ans++;
                    isFlipped.push(i + k - 1);
                }
            }

            if (!isFlipped.empty() && i >= isFlipped.front())
                isFlipped.pop();
        }

        return isFlipped.empty() ? ans : -1;
    }
};