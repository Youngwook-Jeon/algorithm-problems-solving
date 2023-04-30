#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    const int WHITE = 0;
    const int GRAY = 1;
    const int BLACK = 2;

    vector<vector<int>> graph;
    vector<int> colors;
    bool existChars[26];

    int n;
    bool isPossible = true;
    string ans;

    string alienOrder(vector<string> &words)
    {
        n = words.size();
        graph.resize(26);
        colors.resize(26);

        for (auto &word : words)
        {
            for (int i = 0; i < word.size(); i++)
            {
                existChars[word[i] - 'a'] = true;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (words[i].size() > words[j].size() && words[i].rfind(words[j], 0) == 0)
                    return "";
                makeOrderingGraph(words[i], words[j]);
            }
        }

        for (int i = 0; i < 26; ++i)
        {
            if (colors[i] == WHITE && existChars[i] && isPossible)
                dfs(i);
        }

        reverse(ans.begin(), ans.end());

        return (isPossible) ? ans : "";
    }

    void makeOrderingGraph(string &s1, string &s2)
    {
        int m = min(s1.size(), s2.size());

        int i = 0;
        while (i < m && s1[i] == s2[i])
        {
            i++;
        }

        if (i == m)
            return;

        char from = s1[i];
        char to = s2[i];

        graph[from - 'a'].push_back(to - 'a');
    }

    void dfs(int node)
    {
        if (!isPossible)
        {
            return;
        }

        colors[node] = GRAY;

        for (auto &next : graph[node])
        {
            if (colors[next] == WHITE)
                dfs(next);
            else if (colors[next] == GRAY)
            {
                isPossible = false;
            }
        }

        colors[node] = BLACK;
        ans.push_back(node + 'a');
    }
};