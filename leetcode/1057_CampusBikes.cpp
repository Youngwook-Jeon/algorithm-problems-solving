#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

class Solution
{
public:
    int findDist(vector<int> &wpos, vector<int> &bpos)
    {
        return abs(wpos[0] - bpos[0]) + abs(wpos[1] - bpos[1]);
    }

    vector<int> assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes)
    {
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>
            pq;
        vector<vector<tuple<int, int, int>>> workerToBike;

        for (int worker = 0; worker < workers.size(); worker++)
        {
            vector<tuple<int, int, int>> toBike;
            for (int bike = 0; bike < bikes.size(); bike++)
            {
                int dist = findDist(workers[worker], bikes[bike]);
                toBike.push_back({dist, worker, bike});
            }

            sort(toBike.begin(), toBike.end(), greater<tuple<int, int, int>>());
            pq.push(toBike.back());
            toBike.pop_back();
            workerToBike.push_back(toBike);
        }

        vector<bool> availableBikes(bikes.size(), true);
        vector<int> ans(workers.size(), -1);

        while (!pq.empty())
        {
            auto [dist, worker, bike] = pq.top();
            pq.pop();
            if (availableBikes[bike])
            {
                ans[worker] = bike;
                availableBikes[bike] = false;
            }
            else
            {
                pq.push(workerToBike[worker].back());
                workerToBike[worker].pop_back();
            }
        }

        return ans;
    }
};