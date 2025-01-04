#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, int **memo, vector<int> &lev, int log, vector<int> *g)
{
    memo[u][0] = p;
    for (int i = 1; i <= log; i++)
    {
        memo[u][i] = memo[memo[u][i - 1]][i - 1];
    }
    for (int v : g[u])
    {
        if (v != p)
        {
            lev[v] = lev[u] + 1;
            dfs(v, u, memo, lev, log, g);
        }
    }
}

int lca(int u, int v, int log, vector<int> &lev, int **memo)
{
    if (lev[u] < lev[v])
        swap(u, v);

    for (int i = log; i >= 0; i--)
    {
        if (lev[u] - pow(2, i) >= lev[v])
            u = memo[u][i];
    }

    if (u == v)
        return u;

    for (int i = log; i >= 0; i--)
    {
        if (memo[u][i] != memo[v][i])
        {
            u = memo[u][i];
            v = memo[v][i];
        }
    }
}

int main()
{
    int n = 9;
    vector<int> g[n + 1];
    int log = (int)ceil(log2(n));

    // memo[i][j] := ith node's 2^(j)th ancestor in the path
    // memo[i][j] = memo[memo[i][j - 1]][j - 1] if j > 0, memo[i][j] = parent[i] if j == 0
    int **memo = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        memo[i] = new int[log + 1];
    }

    // the level of each node
    vector<int> lev(n + 1);

    for (int i = 0; i < n + 1; i++)
    {
        memset(memo[i], -1, sizeof memo[i]);
    }

    g[1].push_back(2);
    g[2].push_back(1);
    g[1].push_back(3);
    g[3].push_back(1);
    g[1].push_back(4);
    g[4].push_back(1);
    g[2].push_back(5);
    g[5].push_back(2);
    g[3].push_back(6);
    g[6].push_back(3);
    g[3].push_back(7);
    g[7].push_back(3);
    g[3].push_back(8);
    g[8].push_back(3);
    g[4].push_back(9);
    g[9].push_back(4);

    dfs(1, 1, memo, lev, log, g);
    cout << "The LCA of 5 and 9 is " << lca(5, 9, log, lev, memo) << endl;

    return 0;
}