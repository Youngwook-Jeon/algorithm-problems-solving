#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int shortestWay(string source, string target)
    {
        vector<int> charIndArr[26];
        for (int i = 0; i < source.size(); i++)
        {
            charIndArr[source[i] - 'a'].push_back(i);
        }

        int curPos = 0;
        int cnt = 1;

        for (int i = 0; i < target.size(); i++)
        {
            if (charIndArr[target[i] - 'a'].size() == 0)
                return -1;

            vector<int> inds = charIndArr[target[i] - 'a'];
            int index = lower_bound(inds.begin(), inds.end(), curPos) - inds.begin();
            if (index == inds.size())
            {
                cnt++;
                curPos = inds[0] + 1;
            }
            else
            {
                curPos = inds[index] + 1;
            }
        }

        return cnt;
    }
};