#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool isArmstrong(int n)
    {
        int origin = n;
        vector<int> digits;
        int len = 0;
        double su = 0.0;
        while (n > 0)
        {
            digits.push_back(n % 10);
            n /= 10;
            len++;
        }

        for (int digit : digits)
        {
            su += pow((double)digit, (double)len);
        }

        return (int)su == origin;
    }
};