#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(int A[], int N)
    {
        // Your code here
        int ans = 0;
        int tmp = 0;
        int prev = A[0];
        for (int i = 1; i < N; i++)
        {
            if (A[i] > prev)
            {
                tmp++;
            }
            else
            {
                ans = max(tmp, ans);
                tmp = 0;
            }
            prev = A[i];
        }
        ans = max(ans, tmp);
        return ans;
    }
};