#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDigitOne(int n)
    {
        int ans = 0;
        for (long long i = 1; i <= n; i *= 10)
        {
            int now = n / i;
            int remainder = now % 10;
            if (remainder == 0)
            {
                ans += (now / 10) * i;
            }
            else if (remainder == 1)
            {
                ans += (now / 10) * i + (n % i + 1);
            }
            else
            {
                ans += (now / 10 + 1) * i;
            }
        }

        return ans;
    }
};