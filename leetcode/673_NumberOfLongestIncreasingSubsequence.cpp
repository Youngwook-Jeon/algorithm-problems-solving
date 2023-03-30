#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        // pair<int, int> p = table[i];
        // p.first := i까지의 LIS의 길이
        // p.second := i까지의 LIS의 갯수
        vector<pair<int, int>> table(nums.size(), {1, 1});
        int mx = 1;
        int ans = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (table[i].first == table[j].first + 1)
                        table[i].second += table[j].second;
                    if (table[i].first < table[j].first + 1)
                        table[i] = {table[j].first + 1, table[j].second};
                }
            }

            if (table[i].first == mx)
            {
                ans += table[i].second;
            }

            if (table[i].first > mx)
            {
                mx = table[i].first;
                ans = table[i].second;
            }
        }

        return ans;
    }
};