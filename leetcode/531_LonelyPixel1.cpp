#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findLonelyPixel(vector<vector<char>> &picture)
    {
        int m = picture.size(), n = picture[0].size();
        vector<int> bRows(m);
        vector<int> bCols(n);
        vector<pair<int, int>> bPos;
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (picture[i][j] == 'B')
                {
                    bRows[i]++;
                    bCols[j]++;
                    bPos.push_back({i, j});
                }
            }
        }

        for (auto &p : bPos)
        {
            if (bRows[p.first] == 1 && bCols[p.second] == 1)
                ans++;
        }

        return ans;
    }
};