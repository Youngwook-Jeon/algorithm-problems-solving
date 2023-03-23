#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> mp;
    vector<vector<int>> ans;

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        for (int num : nums)
        {
            if (mp.find(num) == mp.end())
                mp.insert({num, 0});
            mp[num] += 1;
        }
        vector<int> v;
        solve(nums, 0, v);
        return ans;
    }

    void solve(vector<int> &nums, int cnt, vector<int> &v)
    {
        int n = nums.size();
        if (cnt == n)
        {
            ans.push_back(v);
            return;
        }

        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            int key = it->first;
            int val = it->second;
            if (val == 0)
                continue;

            v.push_back(key);
            mp[key] -= 1;

            solve(nums, cnt + 1, v);

            mp[key] += 1;
            v.pop_back();
        }
    }
};