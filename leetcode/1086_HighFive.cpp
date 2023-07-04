#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<vector<int>> highFive(vector<vector<int>> &items)
    {
        vector<vector<int>> arr(1001);
        vector<vector<int>> ans;
        for (auto &item : items)
        {
            arr[item[0]].push_back(item[1]);
        }

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i].size())
            {
                sort(arr[i].begin(), arr[i].end(), greater<int>());
                int su = accumulate(arr[i].begin(), arr[i].begin() + 5, 0);
                ans.push_back({i, su / 5});
            }
        }

        return ans;
    }
};