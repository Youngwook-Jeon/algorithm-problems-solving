#include <iostream>
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        string s;
        cin >> n >> s;
        int onesCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                onesCount++;
        }

        if (n == 1)
            cout << onesCount << '\n';
        else
        {
            cout << (onesCount * (onesCount - 1)) / 2 << '\n';
        }
    }
    return 0;
}