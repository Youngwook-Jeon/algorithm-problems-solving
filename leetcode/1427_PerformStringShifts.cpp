#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string stringShift(string s, vector<vector<int>> &shift)
    {
        int totalShift = 0;
        for (auto &arr : shift)
        {
            if (arr[0] == 0)
            {
                totalShift += (-1) * arr[1];
            }
            else
            {
                totalShift += arr[1];
            }
        }

        while (totalShift < 0)
        {
            totalShift += 1;
            leftShift(s);
        }

        while (totalShift > 0)
        {
            totalShift -= 1;
            rightShift(s);
        }

        return s;
    }

    void leftShift(string &s)
    {
        char c = s[0];
        s.erase(0, 1);
        s.push_back(c);
    }

    void rightShift(string &s)
    {
        char c = s.back();
        s.pop_back();
        s.insert(s.begin(), c);
    }
};