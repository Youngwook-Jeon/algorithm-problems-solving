#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        int n = arr.size();
        int diff = (arr.back() - arr.front()) / n;
        int l = 0, h = n - 1;

        while (l < h)
        {
            int mid = (l + h) / 2;
            if (arr[mid] == arr.front() + diff * mid)
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
        }

        return arr.front() + diff * l;
    }
};