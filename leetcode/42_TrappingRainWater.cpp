#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0, h = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while (l < h)
        {
            if (height[l] < height[h])
            {
                if (height[l] < leftMax)
                {
                    ans += leftMax - height[l];
                }
                else
                {
                    leftMax = height[l];
                }
                l++;
            }
            else
            {
                if (height[h] < rightMax)
                {
                    ans += rightMax - height[h];
                }
                else
                {
                    rightMax = height[h];
                }
                h--;
            }
        }

        return ans;
    }
};