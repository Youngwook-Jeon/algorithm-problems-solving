#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            return solve(nums2, nums1);
        return solve(nums1, nums2);
    }

    double solve(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        int l = 0, h = m;
        int maxLeft = 0, minRight = 0;
        int mid = 0;
        double ans = 0;

        while (l <= h)
        {
            mid = (l + h) / 2;
            int j = (n + m + 1) / 2 - mid;
            if (mid < m && nums1[mid] < nums2[j - 1])
            {
                l = mid + 1;
            }
            else if (mid > 0 && nums1[mid - 1] > nums2[j])
            {
                h = mid - 1;
            }
            else
            {
                if (mid == 0)
                {
                    maxLeft = nums2[j - 1];
                }
                else if (j == 0)
                {
                    maxLeft = nums1[mid - 1];
                }
                else
                {
                    maxLeft = max(nums1[mid - 1], nums2[j - 1]);
                }

                if ((m + n) % 2 == 1)
                {
                    ans = (double)maxLeft;
                    break;
                }

                if (mid == m)
                {
                    minRight = nums2[j];
                }
                else if (j == n)
                {
                    minRight = nums1[mid];
                }
                else
                {
                    minRight = min(nums1[mid], nums2[j]);
                }

                ans = ((double)(minRight + maxLeft)) / 2;
                break;
            }
        }

        return ans;
    }
};
