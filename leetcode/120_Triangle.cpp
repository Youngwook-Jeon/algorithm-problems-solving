#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
  int minimumTotal(vector<vector<int>> &triangle)
  {
    int n = triangle.size();
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j <= i; j++)
      {
        int curMin = INT_MAX;
        if (j > 0)
        {
          curMin = triangle[i - 1][j - 1];
        }

        if (j < i)
        {
          curMin = min(curMin, triangle[i - 1][j]);
        }
        int pathSum = curMin + triangle[i][j];
        triangle[i][j] = pathSum;
      }
    }

    return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
  }
};