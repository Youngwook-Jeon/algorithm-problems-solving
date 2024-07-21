#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int k)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    int cnt = 0;
    q.push({i, j});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;
        if (visited[r][c])
            continue;
        visited[r][c] = true;
        if (grid[r][c] == 2)
            cnt++;

        for (int ind = 0; ind < 4; ind++)
        {
            int nextR = r + dr[ind];
            int nextC = c + dc[ind];

            if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m &&
                !visited[nextR][nextC] && grid[nextR][nextC] != 0)
            {
                q.push({nextR, nextC});
            }
        }
    }

    if (cnt > k)
        return 1;
    return 0;
}

int main()
{
    // code
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q, k;
        cin >> n >> m >> q >> k;

        vector<vector<int>> grid(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < q; i++)
        {
            int a, b;
            cin >> a >> b;
            grid[a][b] = 2;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0 && !visited[i][j])
                {
                    cnt += bfs(grid, visited, i, j, k);
                }
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}