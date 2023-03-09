#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() && nums[i] <= 0; i++)
    {
      if (i == 0 || nums[i - 1] != nums[i])
      {
        solve(nums, i, ans);
      }
    }

    return ans;
  }

  void solve(vector<int> &nums, int cur, vector<vector<int>> &ans)
  {
    unordered_set<int> us;
    for (int i = cur + 1; i < nums.size(); i++)
    {
      int target = -nums[cur] - nums[i];
      if (us.count(target))
      {
        ans.push_back({nums[cur], nums[i], target});
        while (i + 1 != nums.size() && nums[i] == nums[i + 1])
        {
          i++;
        }
      }
      us.insert(nums[i]);
    }
  }
};