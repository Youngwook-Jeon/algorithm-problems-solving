#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, int chocos, int sm, int remain, vector<int> &bags, vector<bool> &visited)
{
    if (remain == 0)
        return true;

    if (sm == chocos)
    {
        return dfs(0, chocos, 0, remain - 1, bags, visited);
    }

    for (int i = v; i < bags.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            if (dfs(i + 1, chocos, sm + bags[i], remain, bags, visited))
            {
                return true;
            }
            visited[i] = false;
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        int chocos = 0;
        cin >> n >> k;
        vector<int> bags(n);

        for (int i = 0; i < n; i++)
        {
            cin >> bags[i];
            chocos += bags[i];
        }
        if (chocos % k == 0)
        {
            chocos /= k;
            vector<bool> visited(n);
            bool ans = dfs(0, chocos, 0, k, bags, visited);
            cout << (ans ? "Yes" : "No") << '\n';
        }
        else
        {
            cout << "No" << '\n';
        }
    }
    return 0;
}