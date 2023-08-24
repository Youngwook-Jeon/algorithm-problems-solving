#include <set>
using namespace std;

class Solution
{
public:
    set<int> s;

    int minimumSum(int n, int k)
    {
        int i = 1, j = 0;
        int ans = 0;
        while (j < n)
        {
            bool b = true;
            for (auto it = s.begin(); it != s.end(); ++it)
            {
                if (*(it) + i == k)
                {
                    b = false;
                    continue;
                }
            }
            if (b)
            {
                s.insert(i);
                ans += i;
                j++;
            }
            i++;
        }

        return ans;
    }
};