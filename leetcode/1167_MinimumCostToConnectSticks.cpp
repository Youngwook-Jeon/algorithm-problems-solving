#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int connectSticks(vector<int> &sticks)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        for (auto stick : sticks)
        {
            pq.push(stick);
        }

        while (pq.size() > 1)
        {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            ans += s1 + s2;
            pq.push(s1 + s2);
        }

        return ans;
    }
};