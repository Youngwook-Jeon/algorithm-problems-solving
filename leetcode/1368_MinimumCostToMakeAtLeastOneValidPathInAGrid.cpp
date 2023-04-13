#include <vector>
#include <deque>
#include <unordered_set>
using namespace std;

struct State
{
    int r, c, dir, cost;

    State(int r, int c, int dir, int cost) : r(r), c(c), dir(dir), cost(cost) {}
};

class Solution
{
public:
    int dr[5] = {0, 0, 0, 1, -1};
    int dc[5] = {0, 1, -1, 0, 0};

    int minCost(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = -1;

        deque<State> q;
        unordered_set<int> seen;

        q.push_back({0, 0, grid[0][0], 0});

        while (!q.empty())
        {
            State s = q.front();
            q.pop_front();

            int r = s.r;
            int c = s.c;
            int dir = s.dir;
            int indPos = r * n + c;

            seen.insert(indPos);

            if (r == m - 1 && c == n - 1)
            {
                ans = s.cost;
                break;
            }

            for (int i = 1; i < 5; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || seen.count(nr * n + nc))
                    continue;

                if (dir == i)
                {
                    q.push_front({nr, nc, grid[nr][nc], s.cost});
                }
                else
                {
                    q.push_back({nr, nc, grid[nr][nc], s.cost + 1});
                }
            }
        }

        return ans;
    }
};