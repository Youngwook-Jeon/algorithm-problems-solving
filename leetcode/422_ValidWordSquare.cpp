#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool validWordSquare(vector<string> &words)
    {
        int m = words.size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                if (j >= m || i >= words[j].size() || words[i][j] != words[j][i])
                    return false;
            }
        }

        return true;
    }
};