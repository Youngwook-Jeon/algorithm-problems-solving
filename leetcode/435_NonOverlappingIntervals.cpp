#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        auto comparator = [](vector<int> &v1, vector<int> &v2)
        {
            if (v1[0] == v2[0])
            {
                return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        };
        sort(intervals.begin(), intervals.end(), comparator);
        int lastEndpoint = intervals[0][1];
        int ans = 0;

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (lastEndpoint <= intervals[i][0])
            {
                lastEndpoint = intervals[i][1];
            }
            else if (lastEndpoint < intervals[i][1])
            {
                ans++;
            }
            else
            {
                lastEndpoint = intervals[i][1];
                ans++;
            }
        }

        return ans;
    }
};