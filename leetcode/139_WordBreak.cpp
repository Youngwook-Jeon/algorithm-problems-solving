#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool table[301];

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        table[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (table[j] && us.find(s.substr(j, i - j)) != us.end())
                {
                    table[i] = true;
                    break;
                }
            }
        }

        return table[s.size()];
    }
};