#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int minThrow(int N, int arr[])
    {
        // code here
        unordered_map<int, int> um;
        for (int i = 0; i < 2 * N - 1; i += 2)
        {
            um[arr[i]] = arr[i + 1];
        }

        queue<pair<int, int>> q;
        q.push({1, 0});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int now = p.first;
            int throws = p.second;

            if (now == 30)
                return throws;
            for (int i = 1; i <= 6; i++)
            {
                int next = now + i;
                if (next > 30)
                    break;
                if (um.find(next) != um.end())
                {
                    next = um[next];
                }

                q.push({next, throws + 1});
            }
        }

        return 0;
    }
};