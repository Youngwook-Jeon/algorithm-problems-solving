#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> um;
        unordered_set<int> us;
        for (auto x : arr)
        {
            um[x] += 1;
        }

        for (auto iter = um.begin(); iter != um.end(); ++iter)
        {
            us.insert(iter->second);
        }

        return us.size() == um.size();
    }
};