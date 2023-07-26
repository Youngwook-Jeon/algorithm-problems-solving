#include <vector>
using namespace std;

class ZigzagIterator
{
public:
    int lIter = 0, rIter = 0;
    int lMax = 0, rMax = 0;
    int turn = 0;
    vector<int> v1, v2;
    ZigzagIterator(vector<int> &v1, vector<int> &v2) : v1(v1), v2(v2)
    {
        lMax = v1.size() - 1, rMax = v2.size() - 1;
    }

    int next()
    {
        if (turn == 0)
        {
            turn = 1;
            if (lIter <= lMax)
            {
                return v1[lIter++];
            }
            return v2[rIter++];
        }
        else
        {
            turn = 0;
            if (rIter <= rMax)
            {
                return v2[rIter++];
            }
            return v1[lIter++];
        }
    }

    bool hasNext()
    {
        if (lIter <= lMax || rIter <= rMax)
            return true;
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */