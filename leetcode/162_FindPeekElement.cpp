#include <vector>
using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    int n = nums.size();
    if (nums.size() == 1)
      return 0;

    int l = 0, h = n - 1;
    while (l <= h)
    {
      int mid = (l + h) / 2;

      if (mid > 0 && mid < n - 1 &&
          nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
      {
        return mid;
      }
      else if (mid == 0 && nums[mid] > nums[mid + 1])
        return mid;
      else if (mid == n - 1 && nums[mid] > nums[mid - 1])
        return mid;
      else if (nums[mid] < nums[mid + 1])
        l = mid + 1;
      else
        h = mid - 1;
    }

    return -1;
  }
};