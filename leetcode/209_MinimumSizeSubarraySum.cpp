#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int start = 0, end = 0, cur = 0, ans = INT_MAX;
    for (end = 0; end < nums.size(); end++)
    {
      cur += nums[end];
      while (cur >= target)
      {
        ans = min(ans, end - start + 1);
        cur -= nums[start++];
      }
    }
    return (ans != INT_MAX) ? ans : 0;
  }
};