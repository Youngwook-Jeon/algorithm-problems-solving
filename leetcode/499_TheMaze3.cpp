#include <vector>
#include <string>
#include <climits>
#include <queue>
using namespace std;

struct Info
{
    int r, c, dist;
    string inst;

    Info(int r, int c, int dist, string inst) : r(r), c(c), dist(dist), inst(inst) {}

    bool operator<(const Info info) const
    {
        if (this->dist > info.dist)
            return true;
        else if (this->dist == info.dist)
            return this->inst > info.inst;
        return false;
    }
};

class Solution
{
public:
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};
    char dir[4] = {'d', 'r', 'u', 'l'};
    vector<vector<int>> distances;

    string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole)
    {
        int m = maze.size(), n = maze[0].size();
        distances.resize(m, vector<int>(n, INT_MAX));
        priority_queue<Info> pq;

        distances[ball[0]][ball[1]] = 0;
        pq.push({ball[0], ball[1], 0, ""});
        while (!pq.empty())
        {
            auto info = pq.top();
            pq.pop();
            int r = info.r;
            int c = info.c;
            int dist = info.dist;
            string inst = info.inst;
            if (distances[r][c] < dist)
                continue;
            if (r == hole[0] && c == hole[1])
                return inst;

            for (int i = 0; i < 4; i++)
            {
                int nr = r;
                int nc = c;
                int count = 0;
                while (nr + dr[i] >= 0 && nr + dr[i] < m && nc + dc[i] >= 0 && nc + dc[i] < n && maze[nr + dr[i]][nc + dc[i]] == 0)
                {
                    nr += dr[i];
                    nc += dc[i];
                    count++;
                    if (nr == hole[0] && nc == hole[1])
                        break;
                }
                if (count != 0 && (distances[r][c] + count <= distances[nr][nc]))
                {
                    distances[nr][nc] = distances[r][c] + count;
                    pq.push({nr, nc, distances[nr][nc], inst + dir[i]});
                }
            }
        }

        return "impossible";
    }
};