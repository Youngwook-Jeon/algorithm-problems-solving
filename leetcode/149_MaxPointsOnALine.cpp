#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size(), ans = 2;
        if (n == 1)
            return 1;

        for (int i = 0; i < n; i++)
        {
            unordered_map<double, int> mp;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    mp[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
                }
            }

            for (auto [_, cnt] : mp)
            {
                ans = max(ans, cnt + 1);
            }
        }

        return ans;
    }
};