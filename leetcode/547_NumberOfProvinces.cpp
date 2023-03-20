#include <vector>
using namespace std;

class Solution
{
public:
    bool visited[200];

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int ans = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, i);
                ans++;
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>> &isConnected, int cur)
    {
        if (visited[cur])
            return;
        visited[cur] = true;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (isConnected[cur][i] == 1 && !visited[i])
                dfs(isConnected, i);
        }
    }
};