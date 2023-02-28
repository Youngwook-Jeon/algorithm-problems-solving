#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct State
{
  int r, c, time;
} State;

class Solution
{
public:
  int dr[4] = {1, 0, -1, 0};
  int dc[4] = {0, 1, 0, -1};

  int orangesRotting(vector<vector<int>> &grid)
  {
    int ans = 0;
    int m = grid.size(), n = grid[0].size();
    int nFresh = findNumberOfFresh(grid);
    queue<State> q;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 2)
          q.push({i, j, 0});
      }
    }

    while (!q.empty())
    {
      State s = q.front();
      q.pop();
      int r = s.r, c = s.c;
      int t = s.time;
      ans = max(ans, t);

      for (int i = 0; i < 4; i++)
      {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1)
        {
          q.push({nr, nc, t + 1});
          grid[nr][nc] = 2;
          nFresh--;
        }
      }
    }
    return (nFresh == 0) ? ans : -1;
  }

  int findNumberOfFresh(vector<vector<int>> &grid)
  {
    int ret = 0;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == 1)
          ret++;
      }
    }

    return ret;
  }
};