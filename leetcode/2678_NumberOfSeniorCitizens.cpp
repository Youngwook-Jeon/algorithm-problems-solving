#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int ans = 0;
        for (auto &detail : details)
        {
            if (stoi(detail.substr(11, 2)) > 60)
                ans++;
        }

        return ans;
    }
};