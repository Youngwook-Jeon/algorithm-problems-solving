#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> table;

    int fib(int n)
    {
        if (n <= 1)
            return n;
        table.resize(31, -1);
        table[0] = 0;
        table[1] = 1;

        return solve(n);
    }

    int solve(int n)
    {
        if (table[n] != -1)
            return table[n];

        table[n] = solve(n - 1) + solve(n - 2);
        return table[n];
    }
};