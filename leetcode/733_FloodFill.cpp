#include <vector>
using namespace std;

class Solution
{
public:
  int dr[4] = {1, 0, -1, 0};
  int dc[4] = {0, 1, 0, -1};

  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
  {
    if (image[sr][sc] != color)
    {
      solve(image, sr, sc, image[sr][sc], color);
    }
    return image;
  }

  void solve(vector<vector<int>> &image, int sr, int sc, int original, int newColor)
  {
    if (image[sr][sc] != newColor)
    {
      image[sr][sc] = newColor;
      for (int i = 0; i < 4; i++)
      {
        int nr = sr + dr[i];
        int nc = sc + dc[i];
        if (nr >= 0 && nr < image.size() && nc >= 0 && nc < image[0].size() && image[nr][nc] == original)
        {
          solve(image, nr, nc, original, newColor);
        }
      }
    }
  }
};