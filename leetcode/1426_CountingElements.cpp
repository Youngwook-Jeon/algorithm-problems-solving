#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int countElements(vector<int> &arr)
    {
        unordered_set<int> us(arr.begin(), arr.end());
        int ans = 0;

        for (auto num : arr)
        {
            if (us.find(num + 1) != us.end())
                ans++;
        }

        return ans;
    }
};