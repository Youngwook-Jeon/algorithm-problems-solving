#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 1. Use InDegree array
    vector<int> findOrder1(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegrees(numCourses);
        vector<vector<int>> graph(numCourses);
        vector<int> ans;
        queue<int> q;

        for (auto courses : prerequisites)
        {
            int from = courses[1];
            int to = courses[0];
            graph[from].push_back(to);
            indegrees[to]++;
        }

        for (int i = 0; i < indegrees.size(); i++)
        {
            if (indegrees[i] == 0)
                q.push(i);
        }

        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            ans.push_back(node);

            for (auto next : graph[node])
            {
                indegrees[next]--;
                if (indegrees[next] == 0)
                    q.push(next);
            }
        }

        return (cnt == numCourses) ? ans : vector<int>();
    }

    // 2. Use DFS
    const int WHITE = 0;
    const int GRAY = 1;
    const int BLACK = 2;
    bool isPossible;

    vector<int> colors;
    vector<vector<int>> graph;
    vector<int> topOrder;

    vector<int> findOrder2(int numCourses, vector<vector<int>> &prerequisites)
    {
        init(numCourses);
        makeGraph(numCourses, prerequisites);

        for (int i = 0; i < numCourses; i++)
        {
            if (colors[i] == WHITE)
                dfs(i);
        }

        reverse(topOrder.begin(), topOrder.end());

        return (isPossible) ? topOrder : vector<int>();
    }

    void init(int numCourses)
    {
        colors.resize(numCourses);
        graph.resize(numCourses);
        isPossible = true;
    }

    void makeGraph(int numCourses, vector<vector<int>> &prerequisites)
    {
        for (auto courses : prerequisites)
        {
            int from = courses[1];
            int to = courses[0];
            graph[from].push_back(to);
        }
    }

    void dfs(int node)
    {
        if (!isPossible)
            return;

        colors[node] = GRAY;
        for (auto next : graph[node])
        {
            if (colors[next] == WHITE)
                dfs(next);
            else if (colors[next] == GRAY)
                isPossible = false;
        }
        colors[node] = BLACK;
        topOrder.push_back(node);
    }
};