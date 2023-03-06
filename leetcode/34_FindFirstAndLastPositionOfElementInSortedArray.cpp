#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int first = findOccuranceOf(nums, target, true);
    if (first == -1)
    {
      return {-1, -1};
    }

    int last = findOccuranceOf(nums, target, false);

    return {first, last};
  }

  int findOccuranceOf(vector<int> &nums, int target, bool isFirst)
  {
    int l = 0, h = nums.size() - 1;

    while (l <= h)
    {
      int mid = (h - l) / 2 + l;
      int val = nums[mid];

      if (val == target)
      {
        if (isFirst)
        {
          if (mid == l || nums[mid - 1] != target)
          {
            return mid;
          }

          h = mid - 1;
        }
        else
        {
          if (mid == h || nums[mid + 1] != target)
          {
            return mid;
          }

          l = mid + 1;
        }
      }
      else if (val > target)
      {
        h = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }

    return -1;
  }
};