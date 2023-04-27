#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0;
        int ans = INT_MIN;

        vector<int> leftProfits(n);
        vector<int> rightProfits(n + 1);
        int leftMin = prices[0], rightMax = prices[n - 1];

        for (int i = 1; i < n; i++)
        {
            leftProfits[i] = max(leftProfits[i - 1], prices[i] - leftMin);
            leftMin = min(prices[i], leftMin);

            int j = n - i - 1;
            rightProfits[j] = max(rightProfits[j + 1], rightMax - prices[j]);
            rightMax = max(prices[j], rightMax);
        }

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, leftProfits[i] + rightProfits[i + 1]);
        }

        return ans;
    }
};