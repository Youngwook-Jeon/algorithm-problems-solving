#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    const int INF = INT_MAX;

    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size(), n = dungeon[0].size();

        vector<vector<int>> table(m, vector<int>(n, INF));

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int cur = dungeon[i][j];

                int rightMin = getMinHealthAt(cur, i, j + 1, table);
                int downMin = getMinHealthAt(cur, i + 1, j, table);

                int health = min(rightMin, downMin);
                if (health != INF)
                    table[i][j] = health;
                else
                {
                    table[i][j] = (cur >= 0) ? 1 : 1 - cur;
                }
            }
        }

        return table[0][0];
    }

    int getMinHealthAt(int cur, int r, int c, vector<vector<int>> &table)
    {
        int m = table.size(), n = table[0].size();
        if (r >= m || c >= n)
            return INF;

        int h = table[r][c];
        return max(1, h - cur);
    }
};