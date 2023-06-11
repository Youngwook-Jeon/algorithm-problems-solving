#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Tuple
{
    int r, c, dist;

    Tuple(int r, int c, int dist) : r(r), c(c), dist(dist) {}

    bool operator<(const Tuple t) const
    {
        return this->dist > t.dist;
    }
};

class Solution
{
public:
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};
    vector<vector<bool>> visited;
    vector<vector<int>> distances;

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        int m = maze.size(), n = maze[0].size();
        visited.resize(m, vector<bool>(n, false));
        distances.resize(m, vector<int>(n, INT_MAX));

        Tuple t{start[0], start[1], 0};
        distances[start[0]][start[1]] = 0;
        priority_queue<Tuple> pq;
        pq.push(t);

        while (!pq.empty())
        {
            auto tp = pq.top();
            pq.pop();
            int r = tp.r;
            int c = tp.c;
            int dist = tp.dist;
            if (distances[r][c] < dist)
                continue;

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                int count = 0;
                while (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == 0)
                {
                    nr += dr[i];
                    nc += dc[i];
                    count++;
                }
                if (distances[r][c] + count < distances[nr - dr[i]][nc - dc[i]])
                {
                    distances[nr - dr[i]][nc - dc[i]] = distances[r][c] + count;
                    pq.push({nr - dr[i], nc - dc[i], distances[nr - dr[i]][nc - dc[i]]});
                }
            }
        }

        return distances[destination[0]][destination[1]] == INT_MAX ? -1 : distances[destination[0]][destination[1]];
    }
};