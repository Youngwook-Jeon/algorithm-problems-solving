#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int ans = -1;
        vector<int> left(n);
        vector<int> right(n, n);
        vector<int> height(n);

        for (int i = 0; i < m; i++)
        {
            int curLeft = 0, curRight = n;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    height[j]++;
                }
                else
                {
                    height[j] = 0;
                }
            }

            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    left[j] = max(left[j], curLeft);
                }
                else
                {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }

            for (int j = n - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '1')
                {
                    right[j] = min(right[j], curRight);
                }
                else
                {
                    right[j] = n;
                    curRight = j;
                }
            }

            for (int j = 0; j < n; j++)
            {
                ans = max(ans, (right[j] - left[j]) * height[j]);
            }
        }

        return ans;
    }
};