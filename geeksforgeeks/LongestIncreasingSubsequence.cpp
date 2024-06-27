#include <vector>
using namespace std;

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> tail(n);
       tail[0] = a[0];
       int len = 1;
       
       for (int i = 1; i < n; i++) {
           auto s = tail.begin();
           auto e = tail.begin() + len;
           auto it = lower_bound(s, e, a[i]);
           if (it == e) {
               tail[len++] = a[i];
           } else {
               *it = a[i];
           }
       }
       
       return len;
    }
};