#include <vector>
using namespace std;

class Solution
{
    public:
    //Function to return the maximum sum without adding adjacent elements.
    long long maximumSum(int arr[], int sizeOfArray)
    {
      //Your code here
      if (sizeOfArray == 1) return arr[0];
      else if (sizeOfArray == 2) return max(arr[0], arr[1]);
      
      vector<long long> dp(sizeOfArray);
      dp[0] = arr[0];
      dp[1] = max(arr[0], arr[1]);
      
      for (int i = 2; i < sizeOfArray; i++) {
          dp[i] = max(dp[i - 2] + arr[i], (long long) arr[i]);
          dp[i] = max(dp[i], dp[i - 1]);
      }
      
      return dp[sizeOfArray - 1];
    }
};