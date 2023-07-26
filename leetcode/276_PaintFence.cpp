#include <vector>
using namespace std;

class Solution
{
public:
    int numWays(int n, int k)
    {
        if (n <= 1)
            return k;

        vector<int> table(n + 1);
        table[1] = k;
        table[2] = k * k;
        for (int i = 3; i <= n; i++)
        {
            table[i] = (k - 1) * (table[i - 1] + table[i - 2]);
        }

        return table[n];
    }
};