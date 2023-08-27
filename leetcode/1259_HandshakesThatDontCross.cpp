#include <vector>
using namespace std;

class Solution
{
public:
    const int m = 1000000007;

    int numberOfWays(int numPeople)
    {
        vector<int> dp(numPeople / 2 + 1);
        dp[0] = 1;

        for (int i = 1; i <= numPeople / 2; i++)
        {
            for (int j = 0; j < i; j++)
            {
                (dp[i] += (long long)dp[j] * dp[i - j - 1] % m) %= m;
            }
        }

        return dp[numPeople / 2];
    }
};