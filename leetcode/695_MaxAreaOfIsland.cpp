#include <vector>
using namespace std;

class Solution
{
public:
  int dr[4] = {1, 0, -1, 0};
  int dc[4] = {0, 1, 0, -1};
  bool visited[50][50];
  int val = 0;

  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (!visited[i][j] && grid[i][j] == 1)
        {
          val = 0;
          dfs(grid, i, j);
          ans = max(val, ans);
        }
      }
    }

    return ans;
  }

  void dfs(vector<vector<int>> &grid, int row, int col)
  {
    if (visited[row][col])
      return;

    visited[row][col] = true;
    val += 1;
    for (int i = 0; i < 4; i++)
    {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1 && !visited[nr][nc])
      {
        dfs(grid, nr, nc);
      }
    }
  }
};