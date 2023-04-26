#include <vector>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> table;
    vector<vector<int>> isPalindrome;

    int minCut(string s)
    {
        int n = s.size();
        table.resize(n);
        isPalindrome.resize(n, vector<int>(n));

        verifyPalidrome(s);

        for (int e = 0; e < n; e++)
        {
            int localRes = INT_MAX;
            for (int s = 0; s <= e; s++)
            {
                int val = 0;
                if (isPalindrome[s][e])
                {
                    val = (s == 0) ? 0 : 1 + table[s - 1];
                    localRes = min(val, localRes);
                }
            }
            table[e] = localRes;
        }

        return table[n - 1];
    }

    void verifyPalidrome(string &str)
    {
        for (int e = 0; e < str.size(); e++)
        {
            for (int s = 0; s <= e; s++)
            {
                if (str[s] == str[e] && (s + 1 >= e - 1 || isPalindrome[s + 1][e - 1]))
                {
                    isPalindrome[s][e] = true;
                }
            }
        }
    }
};