#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        vector<double> table(n + 1);
        table[0] = 1.0;
        double x = k > 0 ? 1 : 0;
        for (int i = 1; i <= n; i++)
        {
            table[i] = x / maxPts;
            if (i < k)
                x += table[i];
            if (i - maxPts >= 0 && i - maxPts < k)
                x -= table[i - maxPts];
        }

        return accumulate(table.begin() + k, table.end(), 0.0);
    }
};