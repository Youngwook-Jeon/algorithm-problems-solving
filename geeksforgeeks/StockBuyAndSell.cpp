#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {
        // code here
        vector<vector<int>> ans;
        pair<int, int> prevMin(0, A[0]);
        pair<int, int> prevMax(0, A[0]);
        for (int i = 1; i < n; i++)
        {
            if (prevMax.second < A[i])
            {
                prevMax.second = A[i];
                prevMax.first = i;
            }
            else
            {
                if (prevMax.first != prevMin.first)
                {
                    ans.push_back({prevMin.first, prevMax.first});
                }
                prevMin = make_pair(i, A[i]);
                prevMax = make_pair(i, A[i]);
            }
        }
        if (prevMax.first != prevMin.first)
        {
            ans.push_back({prevMin.first, prevMax.first});
        }

        return ans;
    }
};