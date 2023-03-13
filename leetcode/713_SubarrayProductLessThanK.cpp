#include <vector>
using namespace std;

class Solution
{
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k)
  {
    if (k <= 1)
      return 0;

    int start = 0, end = 0, cur = 1, ans = 0;
    for (end = 0; end < nums.size(); end++)
    {
      cur *= nums[end];
      while (cur >= k)
      {
        cur /= nums[start];
        start++;
      }
      ans += end - start + 1;
    }

    return ans;
  }
};