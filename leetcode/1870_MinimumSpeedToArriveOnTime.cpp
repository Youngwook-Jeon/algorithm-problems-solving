#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int lo = 1, hi = 1000000000;
        int ans = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            double localRes = calculate(mid, dist);
            if (localRes <= hour)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }

    double calculate(int mid, vector<int> &dist)
    {
        double res = 0.0;
        for (int i = 0; i < dist.size(); i++)
        {
            double time = (double)dist[i] / (double)mid;
            res += (i == dist.size() - 1) ? time : ceil(time);
        }

        return res;
    }
};