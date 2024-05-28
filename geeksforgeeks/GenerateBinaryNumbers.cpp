#include <string>
#include <vector>
#include <queue>
using namespace std;

bool isLessOrEqualThan(string s, int n)
{
    int sNum = 0;
    int factor = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        sNum += factor * (s[i] - '0');
        factor *= 2;
    }

    return sNum <= n;
}

vector<string> generate(int N)
{
    // Your code here
    vector<string> ans;
    queue<string> q;
    q.push("1");
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        if (isLessOrEqualThan(s, N))
        {
            ans.push_back(s);
            q.push(s + "0");
            q.push(s + "1");
        }
    }

    return ans;
}