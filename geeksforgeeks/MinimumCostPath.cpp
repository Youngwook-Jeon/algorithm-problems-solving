#include <bits/stdc++.h>
using namespace std;

struct Cell
{
    int x, y;
    int dist;
};

bool operator<(const Cell &a, const Cell &b)
{
    if (a.dist == b.dist)
    {
        if (a.x != b.x)
            return (a.x < b.x);
        else
            return (a.y < b.y);
    }
    return (a.dist < b.dist);
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        set<Cell> st;
        st.insert({0, 0, dist[0][0]});

        while (!st.empty())
        {
            auto c = *st.begin();
            st.erase(st.begin());
            if (c.x == n - 1 && c.y == n - 1)
                break;

            for (int i = 0; i < 4; i++)
            {
                int x = c.x + dx[i];
                int y = c.y + dy[i];

                if (x < 0 || x >= n || y < 0 || y >= n)
                    continue;
                if (dist[y][x] > dist[c.y][c.x] + grid[y][x])
                {
                    if (dist[y][x] != INT_MAX)
                    {
                        st.erase(st.find({x, y, dist[y][x]}));
                    }
                    dist[y][x] = dist[c.y][c.x] + grid[y][x];
                    st.insert({x, y, dist[y][x]});
                }
            }
        }

        cout << dist[n - 1][n - 1] << '\n';
    }
    return 0;
}