#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Your code here
        stack<int> stk;
        vector<int> ans;

        stk.push(0);
        ans.push_back(1);
        for (int i = 1; i < n; i++)
        {
            while (!stk.empty() && price[stk.top()] <= price[i])
                stk.pop();

            if (stk.empty())
            {
                ans.push_back(i + 1);
            }
            else
            {
                ans.push_back(i - stk.top());
            }
            stk.push(i);
        }

        return ans;
    }
};