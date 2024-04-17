#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<int> plusArr, minusArr;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            if (num >= 0)
                plusArr.push_back(num);
            else
                minusArr.push_back(num);
        }

        int pInd = 0, mInd = 0;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0 && pInd < plusArr.size())
            {
                cout << plusArr[pInd] << ' ';
                pInd++;
            }
            else if (i % 2 == 1 && mInd < minusArr.size())
            {
                cout << minusArr[mInd] << ' ';
                mInd++;
            }
        }

        while (pInd < plusArr.size())
        {
            cout << plusArr[pInd] << ' ';
            pInd++;
        }

        while (mInd < minusArr.size())
        {
            cout << minusArr[mInd] << ' ';
            mInd++;
        }

        cout << '\n';
    }

    return 0;
}