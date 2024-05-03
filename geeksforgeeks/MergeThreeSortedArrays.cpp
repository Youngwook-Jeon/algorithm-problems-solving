#include <vector>
using namespace std;

class Solution
{
public:
    // A, B, and C: input sorted arrays
    // Function to merge three sorted vectors or arrays
    // into a single vector or array.
    vector<int> mergeThree(vector<int> &A, vector<int> &B, vector<int> &C)
    {
        // Your code here
        vector<int> D = mergeTwo(A, B);
        return mergeTwo(D, C);
    }

    vector<int> mergeTwo(vector<int> &a, vector<int> &b)
    {
        vector<int> ans(a.size() + b.size());
        int p = 0, i = 0, j = 0;

        while (i < a.size() && j < b.size())
        {
            if (a[i] <= b[j])
            {
                ans[p++] = a[i++];
            }
            else
            {
                ans[p++] = b[j++];
            }
        }

        while (i < a.size())
        {
            ans[p++] = a[i++];
        }

        while (j < b.size())
        {
            ans[p++] = b[j++];
        }

        return ans;
    }
};