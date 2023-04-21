#include <vector>
using namespace std;

class Solution
{
public:
    int table[301][301];

    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                table[i][j] = matrix[i][j] - '0';
                if (table[i][j] == 1)
                    ans = 1;
            }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i + 1 < m && j + 1 < n && table[i][j] != 0)
                {
                    if (table[i + 1][j] == table[i][j + 1])
                    {
                        int num = table[i + 1][j];
                        table[i][j] = (table[i + num][j + num] == 0) ? num : num + 1;
                    }
                    else
                    {
                        table[i][j] = min(table[i + 1][j], table[i][j + 1]) + 1;
                    }
                    ans = max(ans, table[i][j]);
                }
            }
        }

        return ans * ans;
    }
};