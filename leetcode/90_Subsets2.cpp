#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> v;
        backtrack(nums, 0, v);

        return ans;
    }

    void backtrack(vector<int> &nums, int cur, vector<int> &v)
    {
        ans.push_back(v);

        for (int i = cur; i < nums.size(); i++)
        {
            if (i != cur && nums[i] == nums[i - 1])
                continue;
            v.push_back(nums[i]);
            backtrack(nums, i + 1, v);
            v.pop_back();
        }
    }
};