#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        backtrack(candidates, target, 0, 0, v);

        return ans;
    }

    void backtrack(vector<int> &candidates, int target, int cur, int curSum, vector<int> &v)
    {
        if (curSum == target)
        {
            ans.push_back(v);
            return;
        }
        else if (curSum > target)
            return;

        for (int i = cur; i < candidates.size(); i++)
        {
            v.push_back(candidates[i]);
            backtrack(candidates, target, i, curSum + candidates[i], v);
            v.pop_back();
        }
    }
};