#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minimumSemesters(int n, vector<vector<int>> &relations)
    {
        vector<vector<int>> graph(n + 1);
        vector<int> indegrees(n + 1);
        int semesters = 0, cnt = 0;

        for (auto &relation : relations)
        {
            int c1 = relation[0];
            int c2 = relation[1];
            graph[c1].push_back(c2);
            indegrees[c2]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (indegrees[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int sz = q.size();
            semesters++;

            for (int i = 0; i < sz; i++)
            {
                int node = q.front();
                q.pop();
                cnt++;

                for (auto &next : graph[node])
                {
                    indegrees[next]--;
                    if (indegrees[next] == 0)
                        q.push(next);
                }
            }
        }

        return (cnt == n) ? semesters : -1;
    }
};