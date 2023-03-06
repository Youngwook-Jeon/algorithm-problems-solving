#include <vector>
using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    if (nums.size() == 1)
    {
      return (nums[0] == target) ? 0 : -1;
    }

    int pos = findPivot(nums);

    if (nums[pos] == target)
      return pos;

    if (pos == 0)
      return binarySearch(nums, 0, nums.size() - 1, target);

    if (nums[0] > target)
    {
      return binarySearch(nums, pos, nums.size() - 1, target);
    }

    return binarySearch(nums, 0, pos, target);
  }

  int findPivot(vector<int> &nums)
  {
    if (nums[0] < nums.back())
      return 0;
    int l = 0, h = nums.size() - 1;

    while (l <= h)
    {
      int mid = (h - l) / 2 + l;

      if (nums[mid] > nums[mid + 1])
        return mid + 1;

      else
      {
        if (nums[mid] < nums[l])
          h = mid - 1;
        else
          l = mid + 1;
      }
    }

    return 0;
  }

  int binarySearch(vector<int> &nums, int start, int end, int target)
  {
    int l = start, h = end;

    while (l <= h)
    {
      int mid = (h - l) / 2 + l;
      if (nums[mid] == target)
      {
        return mid;
      }
      else if (nums[mid] < target)
      {
        l = mid + 1;
      }
      else
      {
        h = mid - 1;
      }
    }

    return -1;
  }
};