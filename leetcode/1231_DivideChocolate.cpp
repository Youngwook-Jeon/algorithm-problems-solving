#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximizeSweetness(vector<int> &sweetness, int k)
    {
        int numPeople = k + 1;
        int l = *min_element(sweetness.begin(), sweetness.end());
        int h = 0;

        for (auto s : sweetness)
        {
            h += s;
        }
        h /= numPeople;

        while (l < h)
        {
            int mid = (h + l + 1) / 2;
            int chocoPeople = 0;
            int curSweet = 0;

            for (auto s : sweetness)
            {
                curSweet += s;

                if (curSweet >= mid)
                {
                    chocoPeople += 1;
                    curSweet = 0;
                }
            }

            if (chocoPeople >= numPeople)
            {
                l = mid;
            }
            else
            {
                h = mid - 1;
            }
        }

        return h;
    }
};