#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findRLEArray(vector<vector<int>> &encoded1, vector<vector<int>> &encoded2)
    {
        int n = encoded1.size(), m = encoded2.size();
        int i = 0, j = 0;
        int preVal = 0;
        vector<vector<int>> ans;

        while (i < n && j < m)
        {
            auto &arr1 = encoded1[i];
            auto &arr2 = encoded2[j];
            int newVal = arr1[0] * arr2[0];
            int minFreq = min(arr1[1], arr2[1]);

            if (preVal == newVal)
            {
                ans[ans.size() - 1][1] += minFreq;
            }
            else
            {
                ans.push_back({newVal, minFreq});
            }
            arr2[1] -= minFreq;
            arr1[1] -= minFreq;

            if (arr1[1] == 0)
                i++;
            if (arr2[1] == 0)
                j++;

            preVal = newVal;
        }

        return ans;
    }
};