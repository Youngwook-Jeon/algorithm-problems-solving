#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes)
    {
        vector<int> numOnes;
        int ans = 0;

        for (int i = 0; i < sideLength; i++)
        {
            for (int j = 0; j < sideLength; j++)
            {
                int ones = ((width - i + sideLength - 1) / sideLength) * ((height - j + sideLength - 1) / sideLength);
                numOnes.push_back(ones);
            }
        }

        sort(numOnes.begin(), numOnes.end(), greater<int>());

        for (int i = 0; i < maxOnes; i++)
        {
            ans += numOnes[i];
        }

        return ans;
    }
};