#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  // memo[0][i] := max profit on range [0, i) (half open)
  // memo[1][i] := max profit on range [0, i] (closed)
  int memo[2][100];

  int rob(vector<int> &nums)
  {
    if (nums.size() == 1)
      return nums[0];

    if (nums.size() == 2)
      return max(nums[0], nums[1]);

    int ans = 0;
    memo[1][0] = nums[0];
    memo[0][1] = memo[1][0];
    memo[1][1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
      memo[0][i] = max(memo[1][i - 1], memo[0][i - 1]);
      memo[1][i] = max(memo[1][i - 2], memo[0][i - 1]) + nums[i];
    }

    return max(memo[0][nums.size() - 1], memo[1][nums.size() - 1]);
  }
};