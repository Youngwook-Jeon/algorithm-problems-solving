#include <vector>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        int ans = 1;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({end[i], start[i]});
        }
        sort(v.begin(), v.end());
        int prevEnd = v[0].first;
        for (int i = 1; i < n; i++)
        {
            if (v[i].second > prevEnd)
            {
                ans++;
                prevEnd = v[i].first;
            }
        }

        return ans;
    }
};