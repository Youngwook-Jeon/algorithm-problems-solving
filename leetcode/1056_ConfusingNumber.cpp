#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool confusingNumber(int n)
    {
        unordered_map<int, int> table({{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}});

        int k = 1;
        int m = n;
        int res = 0;
        while (m >= 10)
        {
            k *= 10;
            m /= 10;
        }

        m = n;
        int t = 1;
        while (m > 0)
        {
            int num = m / k;
            if (table.find(num) == table.end())
                return false;
            res = res + t * table[num];
            t *= 10;
            m %= k;
            k /= 10;
        }

        return (res != n) ? true : false;
    }
};