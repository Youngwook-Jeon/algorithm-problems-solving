#include <functional>
using namespace std;
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class ArrayReader
{
public:
    int query(int a, int b, int c, int d);

    int length();
};

class Solution
{
public:
    int diffInd = -1, equalCnt = 1, diffCnt = 0;
    int n = 0;

    int guessMajority(ArrayReader &reader)
    {
        n = reader.length();
        int query0123 = reader.query(0, 1, 2, 3);
        int query1234 = reader.query(1, 2, 3, 4);

        function<void(bool, int)> f = [this](bool eq, int i)
        {
            if (eq)
                equalCnt++;
            else
            {
                diffCnt++;
                diffInd = i;
            }
        };

        for (int i = 4; i < n; i++)
        {
            f(query0123 == reader.query(1, 2, 3, i), i);
        }
        f(query1234 == reader.query(0, 2, 3, 4), 1);
        f(query1234 == reader.query(0, 1, 3, 4), 2);
        f(query1234 == reader.query(0, 1, 2, 4), 3);

        if (equalCnt > diffCnt)
            return 0;
        else if (equalCnt < diffCnt)
            return diffInd;
        return -1;
    }
};