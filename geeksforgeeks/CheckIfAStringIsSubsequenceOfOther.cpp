#include <string>
using namespace std;

class Solution
{
public:
    // Function to check if a string is subsequence of other string.
    bool isSubSequence(string A, string B)
    {
        // code here
        if (A.size() > B.size())
            return solve(B, A);
        return solve(A, B);
    }

    bool solve(const string &A, const string &B)
    {
        int a = A.size(), b = B.size();
        int i, j;
        for (i = 0, j = 0; i < a, j < b;)
        {
            if (A[i] == B[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }

        if (i == a)
            return true;
        return false;
    }
};