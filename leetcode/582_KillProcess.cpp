#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
    {
        unordered_map<int, vector<int>> mp;
        vector<int> ans;

        for (int i = 0; i < ppid.size(); i++)
        {
            mp[ppid[i]].push_back(i);
        }

        queue<int> q;
        q.push(kill);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto next : mp[node])
            {
                q.push(pid[next]);
            }
        }

        return ans;
    }
};