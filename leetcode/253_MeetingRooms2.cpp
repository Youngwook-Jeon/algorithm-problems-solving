#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(intervals.begin(), intervals.end());

        pq.push(intervals[0][1]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (pq.top() <= intervals[i][0])
                pq.pop();

            pq.push(intervals[i][1]);
        }

        return pq.size();
    }
};