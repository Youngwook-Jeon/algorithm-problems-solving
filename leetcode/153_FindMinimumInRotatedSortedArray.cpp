#include <vector>
using namespace std;

class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    if (nums.size() == 1)
      return nums[0];

    int l = 0, h = nums.size() - 1;

    while (l <= h)
    {
      int mid = (l + h) / 2;
      if (nums[mid] > nums[mid + 1])
        return nums[mid + 1];

      if (nums[mid] > nums.back())
      {
        l = mid + 1;
      }
      else
      {
        h = mid - 1;
      }
    }

    return nums[l];
  }
};