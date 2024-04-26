// Function to find square root
// x: element to find square root
typedef long long int lli;

class Solution
{
public:
    lli floorSqrt(lli x)
    {
        // Your code goes here
        lli l = 0, h = x;
        lli ans = 0;
        while (l <= h)
        {
            lli mid = (l + h) / 2;
            lli sq = mid * mid;
            if (sq == x)
                return mid;
            else if (sq < x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        return ans;
    }
};