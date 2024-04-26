/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
public:
    int peakElement(int arr[], int n)
    {
        // Your code here
        int l = 0, h = n - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]))
                return mid;
            else if (mid > 0 && arr[mid - 1] >= arr[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }

        return -1;
    }
};