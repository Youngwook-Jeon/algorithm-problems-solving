#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> ans;

  vector<vector<int>> permute(vector<int> &nums)
  {
    backtrack(nums, 0);
    return ans;
  }

  void backtrack(vector<int> &nums, int pos)
  {
    if (pos == nums.size())
    {
      ans.push_back(nums);
      return;
    }

    for (int i = pos; i < nums.size(); i++)
    {
      swap(nums[pos], nums[i]);
      backtrack(nums, pos + 1);
      swap(nums[pos], nums[i]);
    }
  }
};