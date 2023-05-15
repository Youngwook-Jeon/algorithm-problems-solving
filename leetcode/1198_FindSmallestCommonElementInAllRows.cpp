#include <vector>
using namespace std;

class Solution
{
public:
    int smallestCommonElement(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        int curMax = 0, cnt = 0;
        vector<int> positions(m);

        while (true)
        {
            for (int i = 0; i < m; i++)
            {
                while (positions[i] < n && mat[i][positions[i]] < curMax)
                {
                    positions[i]++;
                }
                if (positions[i] >= n)
                    return -1;

                if (curMax != mat[i][positions[i]])
                {
                    cnt = 1;
                    curMax = mat[i][positions[i]];
                }
                else if (++cnt == m)
                    return curMax;
            }
        }

        return -1;
    }
};