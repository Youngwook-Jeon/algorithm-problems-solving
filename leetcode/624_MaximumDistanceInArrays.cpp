#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int ans = 0;
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++)
        {
            ans = max(ans, max(abs(arrays[i][0] - maxVal), abs(arrays[i].back() - minVal)));
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i].back());
        }

        return ans;
    }
};