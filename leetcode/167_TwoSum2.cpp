#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int low = 0, high = numbers.size() - 1;
        vector<int> ret(2);
        while (true)
        {
            if (numbers[low] + numbers[high] == target)
            {
                ret[0] = low + 1;
                ret[1] = high + 1;
                break;
            }

            if (numbers[low] + numbers[high] < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }

        return ret;
    }
};
