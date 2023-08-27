#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<char>> parsedOptions;

    vector<string> expand(string s)
    {
        parse(s);

        vector<string> ans;
        makeWords("", ans);
        return ans;
    }

    void parse(string &s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            vector<char> cur;

            if (s[i] != '{')
            {
                cur.push_back(s[i]);
            }
            else
            {
                while (s[i] != '}')
                {
                    if (s[i] >= 'a' && s[i] <= 'z')
                        cur.push_back(s[i]);
                    i++;
                }
                sort(cur.begin(), cur.end());
            }

            parsedOptions.push_back(cur);
        }
    }

    void makeWords(string s, vector<string> &vec)
    {
        if (s.size() == parsedOptions.size())
        {
            vec.push_back(s);
            return;
        }

        vector<char> cur = parsedOptions[s.size()];

        for (auto c : cur)
        {
            s = s + c;
            makeWords(s, vec);
            s.pop_back();
        }
    }
};