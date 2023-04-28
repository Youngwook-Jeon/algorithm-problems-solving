#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;
        vector<vector<int>> table(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(ans, dfs(i, j, table, matrix));
            }
        }

        return ans;
    }

    int dfs(int r, int c, vector<vector<int>> &table, vector<vector<int>> &matrix)
    {
        if (table[r][c] != 0)
            return table[r][c];
        int m = table.size(), n = table[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c])
            {
                table[r][c] = max(table[r][c], dfs(nr, nc, table, matrix));
            }
        }
        table[r][c] += 1;

        return table[r][c];
    }
};