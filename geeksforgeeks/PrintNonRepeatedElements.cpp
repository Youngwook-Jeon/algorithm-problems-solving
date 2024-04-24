#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // arr[]: input array
    // n: size of array
    // Function to return non-repeated elements in the array.
    vector<int> printNonRepeated(int arr[], int n)
    {
        // Your code here
        unordered_map<int, int> um;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            um[arr[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (um[arr[i]] == 1)
                ans.push_back(arr[i]);
        }

        return ans;
    }
};