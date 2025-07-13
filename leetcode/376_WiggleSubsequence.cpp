#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> plus(n);
        vector<int> minus(n);
        plus[0] = minus[0] = 1;

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                plus[i] = minus[i - 1] + 1;
                minus[i] = minus[i - 1];
            }
            else if (nums[i] < nums[i - 1])
            {
                minus[i] = plus[i - 1] + 1;
                plus[i] = plus[i - 1];
            }
            else
            {
                minus[i] = minus[i - 1];
                plus[i] = plus[i - 1];
            }
        }

        return max(plus[n - 1], minus[n - 1]);
    }
};