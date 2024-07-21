#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n + 1);
        vector<bool> visited(n + 1);

        for (int i = 0; i < m; i++)
        {
            int c1, c2;
            cin >> c1 >> c2;
            adj[c1].push_back(c2);
        }

        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            visited[v] = true;

            for (int next : adj[v])
            {
                q.push(next);
            }
        }

        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << "No" << '\n';
        }
        else
        {
            cout << "Yes" << '\n';
        }
    }
    return 0;
}