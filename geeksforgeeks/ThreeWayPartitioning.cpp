#include <vector>
using namespace std;

class Solution
{
public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        // code here
        int lo = 0, hi = array.size() - 1;
        for (int i = 0; i <= hi;)
        {
            if (array[i] < a)
            {
                if (i == lo)
                {
                    i++;
                    lo++;
                }
                else
                {
                    swap(array[i++], array[lo++]);
                }
            }
            else if (array[i] > b)
            {
                swap(array[i], array[hi--]);
            }
            else
            {
                i++;
            }
        }
    }
};