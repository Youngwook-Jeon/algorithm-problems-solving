#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};

    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // Code here
        queue<pair<int, int>> q;
        vector<vector<int>> visited(N + 1, vector<int>(N + 1, -1));

        q.push({KnightPos[0], KnightPos[1]});
        visited[KnightPos[0]][KnightPos[1]] = 0;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int pX = p.first;
            int pY = p.second;
            if (pX == TargetPos[0] && pY == TargetPos[1])
                return visited[pX][pY];

            for (int i = 0; i < 8; i++)
            {
                int nextX = pX + dx[i];
                int nextY = pY + dy[i];

                if (nextX < 1 || nextX > N || nextY < 1 || nextY > N)
                    continue;
                if (visited[nextX][nextY] == -1)
                {
                    q.push({nextX, nextY});
                    visited[nextX][nextY] = visited[pX][pY] + 1;
                }
            }
        }

        return -1;
    }
};