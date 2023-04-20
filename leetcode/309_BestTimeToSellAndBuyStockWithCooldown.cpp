#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int sold = INT_MIN, held = INT_MIN, reset = 0;

        for (auto price : prices)
        {
            int prevSold = sold;
            sold = held + price;
            held = max(held, reset - price);
            reset = max(prevSold, reset);
        }

        return max(sold, reset);
    }
};