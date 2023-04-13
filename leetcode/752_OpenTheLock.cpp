#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        queue<pair<string, int>> q;
        unordered_set<string> deads;
        unordered_set<string> seen;
        int ans = -1;
        for (string s : deadends)
        {
            deads.insert(s);
        }
        q.push({"0000", 0});
        seen.insert("0000");

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            string s = p.first;
            int dist = p.second;
            if (deads.find(s) != deads.end())
                continue;

            if (s == target)
            {
                ans = dist;
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                string ns(s);
                ns[i] = (s[i] == '9') ? '0' : s[i] + 1;
                if (deads.find(ns) == deads.end())
                {
                    if (seen.find(ns) == seen.end())
                    {
                        q.push({ns, dist + 1});
                        seen.insert(ns);
                    }
                }

                ns[i] = (s[i] == '0') ? '9' : s[i] - 1;
                if (deads.find(ns) == deads.end())
                {
                    if (seen.find(ns) == seen.end())
                    {
                        q.push({ns, dist + 1});
                        seen.insert(ns);
                    }
                }
            }
        }

        return ans;
    }
};