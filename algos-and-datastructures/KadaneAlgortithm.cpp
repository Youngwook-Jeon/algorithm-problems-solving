// Find the max sum of subarrays within an array.
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < a.size(); i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }

    return max_so_far;
}