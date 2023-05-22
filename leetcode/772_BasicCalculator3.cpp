#include <string>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int i = 0;
        return parseExpr(s, i);
    }

    int parseExpr(string &s, int &i)
    {
        vector<int> ans;
        char prevOp = '+';
        for (; i < s.size() && prevOp != ')'; i++)
        {
            long n = (s[i] == '(') ? parseExpr(s, ++i) : parseNum(s, i);
            switch (prevOp)
            {
            case '+':
                ans.push_back(n);
                break;
            case '-':
                ans.push_back(-n);
                break;
            case '*':
                ans.back() *= n;
                break;
            case '/':
                ans.back() /= n;
                break;
            }
            prevOp = s[i];
        }

        return accumulate(ans.begin(), ans.end(), 0);
    }

    long parseNum(string &s, int &i)
    {
        long num = 0;
        while (i < s.size() && isdigit(s[i]))
        {
            num = s[i++] - '0' + 10 * num;
        }

        return num;
    }
};