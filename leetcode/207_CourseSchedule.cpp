#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int count = 0;
        vector<vector<int>> graph(numCourses);
        vector<int> indegrees(numCourses);
        queue<int> q;

        for (auto courses : prerequisites)
        {
            int from = courses[1];
            int to = courses[0];

            indegrees[to]++;
            graph[from].push_back(to);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (indegrees[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            if (graph[node].size() > 0)
            {
                for (auto next : graph[node])
                {
                    indegrees[next]--;
                    if (indegrees[next] == 0)
                        q.push(next);
                }
            }
        }

        return count == numCourses;
    }
};