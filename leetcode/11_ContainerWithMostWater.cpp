#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int ans = INT_MIN;
    int l = 0, h = height.size() - 1;

    while (l <= h)
    {
      int area = min(height[l], height[h]) * (h - l);
      ans = max(area, ans);

      if (height[l] < height[h])
      {
        l++;
      }
      else
      {
        h--;
      }
    }

    return ans;
  }
};