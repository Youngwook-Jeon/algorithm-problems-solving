#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<char>> pairs = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'9', '6'}, {'8', '8'}};

    vector<string> findStrobogrammatic(int n)
    {
        return helper(n, n);
    }

    vector<string> helper(int remain, int target)
    {
        if (remain == 0)
            return {""};
        else if (remain == 1)
            return {"0", "1", "8"};

        vector<string> cur;
        vector<string> prev = helper(remain - 2, target);

        for (auto &pair : pairs)
        {
            for (auto &num : prev)
            {
                if (pair[0] != '0' || remain != target)
                {
                    cur.push_back(pair[0] + num + pair[1]);
                }
            }
        }

        return cur;
    }
};