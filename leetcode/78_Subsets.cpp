#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> v;
        backtrack(nums, 0, v);
        return ans;
    }

    void backtrack(vector<int> &nums, int cur, vector<int> &v)
    {
        if (cur == nums.size())
        {
            ans.push_back(v);
            return;
        }

        backtrack(nums, cur + 1, v);
        v.push_back(nums[cur]);
        backtrack(nums, cur + 1, v);
        v.pop_back();
    }
};