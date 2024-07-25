#include <vector>
using namespace std;

class Solution
{
public:
    int findMinTime(int N, vector<int> &A, int L)
    {
        // write your code here
        int l = 1, h = 1e9;

        while (l < h)
        {
            int mid = l + (h - l) / 2;
            if (check(A, N, L, mid))
            {
                h = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return h;
    }

    bool check(vector<int> &A, int N, int L, int t)
    {
        int cnt = 0;
        for (int i = 0; i < L; i++)
        {
            int x = t;
            int rank = A[i];
            while (x > 0)
            {
                x -= rank;
                if (x >= 0)
                {
                    cnt++;
                    rank += A[i];
                }
            }
        }

        return cnt >= N;
    }
};