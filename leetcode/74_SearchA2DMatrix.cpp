#include <vector>
using namespace std;

class Solution
{
public:
  // Alternative way: Use binary search from l = 0 to h = m * n - 1
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int rowInd = findRowIndex(matrix, target);
    if (rowInd == -1)
      return false;

    return binarySearch(matrix, rowInd, target);
  }

  int findRowIndex(vector<vector<int>> &matrix, int target)
  {
    int l = 0, h = matrix.size() - 1;

    while (l <= h)
    {
      int mid = (h - l) / 2 + l;

      if (matrix[mid][0] <= target)
      {
        l = mid + 1;
      }
      else
      {
        h = mid - 1;
      }
    }

    return l - 1;
  }

  bool binarySearch(vector<vector<int>> &matrix, int row, int target)
  {
    int l = 0, h = matrix[0].size() - 1;

    while (l <= h)
    {
      int mid = (h - l) / 2 + l;

      if (matrix[row][mid] == target)
        return true;
      else if (matrix[row][mid] < target)
        l = mid + 1;
      else
        h = mid - 1;
    }

    return false;
  }
};